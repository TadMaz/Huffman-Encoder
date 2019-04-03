// HuffmanTree.h

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <memory>
#include "HuffmanNode.h"
#include <unordered_map>
#include <vector>

namespace MZRTAD001
{   
    class HuffmanTree
    {
    private:
        std::shared_ptr<MZRTAD001::HuffmanNode> root;
        std::unordered_map<char,std::string> encoder;

    public:
        HuffmanTree(); 
        ~HuffmanTree();
        
        void buildTree(std::unordered_map<char,int> charFreqMap);
        // build the Huffman Tree

        void constructCodes(std::string code, std::shared_ptr<MZRTAD001::HuffmanNode> node);

        std::shared_ptr<MZRTAD001::HuffmanNode> getRoot();

        std::unordered_map<char,std::string>* getEncoder();

        std::string compressData(std::vector<std::string>& textLines,std::unordered_map<char,std::string>& encoder);
        //compress data

        void writeOutput(std::string& buffer , std::string fileName);
    };

    class CompareNodes{
        
    public:
        bool operator() (std::shared_ptr<MZRTAD001::HuffmanNode> a ,std::shared_ptr<MZRTAD001::HuffmanNode> b);
    };

}
#endif 