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

using namespace std;

namespace MZRTAD001{

    //Constructor
    HuffmanTree::HuffmanTree(){
        root = nullptr;
    }

    HuffmanTree::~HuffmanTree(){
        root = nullptr;
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
            
            //HuffmanNode current = minHeap.top();
            //cout<<current.getCharacter()<<" "<<current.getFrequency()<<endl;

            //Pop 2 nodes with lowest frequencies 
            shared_ptr<HuffmanNode> left = minHeap.top();
            minHeap.pop();

            shared_ptr<HuffmanNode> right = minHeap.top();
            minHeap.pop();

            //Sum frequncies of top 2 nodes
            int totalFreq = right->getFrequency()+ left->getFrequency();

            //make new internal node
            shared_ptr<HuffmanNode> internalNode(new HuffmanNode('#',totalFreq));

            internalNode->setLeft(left);
            internalNode->setRight(right);

            cout<<"Left "<<left->getFrequency()<<" Right: "<<right->getFrequency()<<" Total: "<<totalFreq<<endl;

            //Add internal Node into minHeap
            minHeap.push(internalNode);
        }

    }
       
    //compress data
    void HuffmanTree::compressData(){


    }
            
    //define how to compare nodes
    bool CompareNodes::operator() (std::shared_ptr<MZRTAD001::HuffmanNode> a ,std::shared_ptr<MZRTAD001::HuffmanNode> b){

        return (*a).getFrequency()> (*b).getFrequency();
    }

}