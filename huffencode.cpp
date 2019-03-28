//Tadiwanashe Mazara
//Huffman Encoder
//Driver class for Huffman Encoder
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(int argv , char*argc[] ){


    //open input text file
    ifstream input;
    string text;

    input.open("Test.txt");

    if (!input){
        cerr<<"Falied to open text file : Test.txt"<<endl;
    }

    input>>text;

    cout<<text<<endl;
    
    //get frequencies of each letter in file and return map
    //std::unordered_map<char,int> getFrequencies(std::string);

    //close file

    //create Huffman Tree

    //return Output
    
}

namespace MZRTAD001{
    
    std::unordered_map<char,int> getFrequencies(std::string){

    }
}