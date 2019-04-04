//Tadiwanashe Mazara
//Huffman Encoder
//Driver class for Huffman Encoder

#include "huffencode.h"

using namespace std;

int main(int argv , char*argc[] ){

    //objects to store data
    vector<string> textLines;
    unordered_map<char,int> char_freq_map;


    //File Names

    string fileName = "Outfile";
    //Huffman Tree
     MZRTAD001::HuffmanTree tree;

    if (MZRTAD001::loadTextFile("Test.txt", textLines))
    {
        //get frequencies of each letter in file and return map
        MZRTAD001::getFrequencies(textLines, char_freq_map);

        //unordered_map<char,int> ::iterator itr;
        
        // cout<<"Showing output"<<endl;
        // for (itr = char_freq_map.begin(); itr!= char_freq_map.end(); itr++){
        //     cout<<itr->first<<" "<<itr->second<<endl;
        // }

        //Build The Huffman Tree
        tree.buildTree(char_freq_map);
        tree.constructCodes("",tree.getRoot());

        unordered_map<char, string>* encode = tree.getEncoder();

        std::unordered_map<char,string>::iterator it;

        for( it = encode->begin(); it!= encode->end(); it++){
            cout<<it->first<<" "<<it->second<<endl;
        }

        string buffer = tree.compressData(textLines,*encode);

        tree.writeOutput(buffer, fileName);

        tree.writeHeader(*encode,fileName);

        tree.writeBitstream(buffer,fileName);

        tree.readBitstream(fileName);
        
    }


    //return Output
    
}

namespace MZRTAD001{
    
    //loads the Text file to be encoded
    bool loadTextFile(string fileName,vector<string>& textLines){
        
        //open input text file
        ifstream input;
        string text;

        input.open("Test.txt");

        if (!input){
            cerr<<"Falied to open text file : Test.txt"<<endl;
            return false;
        }
    

        while(std::getline(input, text)){
            //cout<<text<<endl;
            textLines.push_back(text);    
        }
        input.close();
        return true;
    }

    //calculates the frequecy of each character in the text file
    void getFrequencies(vector<string>& textLines, unordered_map<char,int>& charFreqMap){
        
        //for each line(string), select a character
        //if key not in map, add key and value
        //else increment the value of the key.

        for (int i = 0; i<textLines.size(); i++){   
            
            string line = textLines[i];

            for (int j = 0; j<line.length();j++){
               
                char character = line[j];

                if(charFreqMap.find(character) == charFreqMap.end()){
                    
                    charFreqMap[character] = 1;

                } else { charFreqMap[character] +=1; }

            }
        }
    }
}