//Tadiwanashe Mazara
//Assignment 3
//Huffman encoder
//March 2019

#include "HuffmanTree.h"
#include <queue> 
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bitset>

using namespace std;

namespace MZRTAD001{

    //Constructor
    HuffmanTree::HuffmanTree(){
        root = nullptr;
    }

    HuffmanTree::~HuffmanTree(){
        root = nullptr;
    }

    std::shared_ptr<MZRTAD001::HuffmanNode> HuffmanTree::getRoot(){
        return root;
    }

    //build tree
    void HuffmanTree::buildTree(std::unordered_map<char,int> charFreqMap){

        //create minHeap(priority queue from frequency char map)
        priority_queue< HuffmanNode, vector<shared_ptr<HuffmanNode>>, CompareNodes > minHeap;

        //insert nodes into min heap
        unordered_map<char,int>::iterator itr;

        for (itr = charFreqMap.begin(); itr!= charFreqMap.end();itr++){

            shared_ptr<HuffmanNode> currentNode(new HuffmanNode((char)itr->first, itr->second));
            minHeap.push(currentNode);
        }

        while(minHeap.size()>1 ){
            
            //if only one element is contained in the MinHeap

           
            //Pop 2 nodes with lowest frequencies 
            shared_ptr<HuffmanNode> left = minHeap.top();
            minHeap.pop();

            shared_ptr<HuffmanNode> right = minHeap.top();
            minHeap.pop();

            //Sum frequncies of top 2 nodes
            int totalFreq = right->getFrequency()+ left->getFrequency();

            //make new internal node
            shared_ptr<HuffmanNode> internalNode(new HuffmanNode((char)0,totalFreq));

            internalNode->setLeft(left);
            internalNode->setRight(right);

            //cout<<"Left "<<left->getFrequency()<<" Right: "<<right->getFrequency()<<" Total: "<<totalFreq<<endl;

            //Add internal Node into minHeap
            minHeap.push(internalNode);

            //Complete building Huffman Tree
            if (minHeap.size() == 1) { root = internalNode; } 
            
            //cout<<"Size :"<<minHeap.size()<<endl;
        }

    }

    void HuffmanTree::constructCodes(string code, std::shared_ptr<MZRTAD001::HuffmanNode> node){

        if (node->getCharacter()!= (char)0){

            encoder[node->getCharacter()] = code;
        }

        if (node->getLeft() != nullptr)
             constructCodes(code+"0",node->getLeft());

        if(node->getRight() != nullptr)
            constructCodes(code+"1", node->getRight());
      
    }

    std::unordered_map<char,string>* HuffmanTree::getEncoder(){
        return &encoder;
    }  


    //compress data
    string HuffmanTree::compressData(std::vector<string>& textLines,std::unordered_map<char,string>& encoder){
        
        string buffer;

        for (int i = 0; i<textLines.size(); i++){   
            
            string line = textLines[i];

            for (int j = 0; j<line.length();j++){
               
                char character = line[j];

                buffer += encoder.at(character);
            }
        }

        return buffer;
    }

    void HuffmanTree::writeOutput(std::string& buffer , std::string fileName){

        //initialise file output stream
        ofstream outfile;

        //open output file
        //string filename = "Outfile.hdr";
        outfile.open(fileName);

        if(!outfile){
            cerr<<"Failed to open file : "<<fileName<<" to write code table"<<endl;
            return;
        }
        outfile<<buffer.c_str();

        outfile.close();
    }

    void HuffmanTree::writeHeader(std::unordered_map<char,std::string>& encoder, std::string fileName){
        
        //initialise file output stream
        ofstream outfile;

        //open output file
        outfile.open(fileName+".hdr");
        outfile<<encoder.size()<<endl;

        for(const auto &n: encoder){
            outfile<<n.first<<" | "<<n.second<<endl;
        }
    }

    void HuffmanTree::writeBitstream(std::string buffer , std::string fileName){

        // The Output Stream
        ofstream outfile;

        //open output file
        outfile.open(fileName+".bin");

        cout<<"Writing bit stream to bin file ..."<<endl;

        //Number of bits and bytes required.
        int noOfBits = buffer.size();
        int noOfBytes = noOfBits/8 + (noOfBits%8 ? 1 : 0);

        char bitStream[noOfBytes];

        // initialise to stream of zeros
        for(int i = 0; i<noOfBytes; i++){
            bitStream[i] = 0;
        }
        
        // Iterate through the bits in buffer
        int byteNo;    
        int shift;

        for(int i = 0; i < noOfBits; i++){
         
            byteNo = i/8;
            shift = i%8;
            //convert bit at this position to match the output string - shift is dependant on 
            //index in output sting.
            if (buffer[i] == '1'){

                bitStream[byteNo] |= 1 << (7-shift);
            }
        }
        
        // print the header and bitstream

        outfile<< noOfBits<<endl;
        for (int i =0; i < noOfBytes; i++){
            bitset<8> stream(bitStream[i]);

            if(i==noOfBytes-1){
                outfile << stream;
            }
            outfile << stream <<" ";
        }
    }

    void HuffmanTree::readBitstream(std::string fileName){

        //Open file for reading

        //Get number of bits and create 

        ifstream inFile;
        int noOfBits;
        int noOfBytes;
        
        inFile.open(fileName+".bin");
        if (!inFile) {
            cerr << "Unable to open file "<<fileName<<endl;
            exit(1); // terminate with error
        }
        
        inFile>>noOfBits;
        cout<<noOfBits<<endl;

        string unpackedStream;
        char currentBit;
        int counter = noOfBits;

        while (!inFile.eof()) {
            inFile>>currentBit>>ws;
            unpackedStream+= currentBit;
            counter++;
        }
        
        inFile.close();

        cout<< unpackedStream<<endl;
        cout<<counter<<endl;
    }

    //define how to compare nodes
    bool CompareNodes::operator() (std::shared_ptr<MZRTAD001::HuffmanNode> a ,std::shared_ptr<MZRTAD001::HuffmanNode> b){

        return (*a).getFrequency()> (*b).getFrequency();
    }

}