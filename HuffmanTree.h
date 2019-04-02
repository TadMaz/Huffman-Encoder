// HuffmanTree.h

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <memory>
#include "HuffmanNode.h"
#include <unordered_map>

namespace MZRTAD001
{   
    class HuffmanTree
    {
    private:
        std::shared_ptr<MZRTAD001::HuffmanNode> root;

    public:
        HuffmanTree(); 
        ~HuffmanTree();
        
        void buildTree(std::unordered_map<char,int> charFreqMap);
        // build the Huffman Tree

        void compressData();
        //compress data
    };

    class CompareNodes{
        
    public:
        bool operator() (std::shared_ptr<MZRTAD001::HuffmanNode> a ,std::shared_ptr<MZRTAD001::HuffmanNode> b);
    };

}
#endif 