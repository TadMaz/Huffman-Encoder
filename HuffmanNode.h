//Huffman Node

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

// a class representing a Huffman Tree node

namespace MZRTAD001
{
    class HuffmanNode
    {
    private:
        char character;
        int frequency;
        std::shared_ptr<HuffmanNode> left;
        std::shared_ptr<HuffmanNode> right; 

    public:
        HuffmanNode(/* args */);
        ~HuffmanNode();
    };
    
    //constructor 
    HuffmanNode::HuffmanNode(/* args */)
    {

    }
    
    //destructor
    HuffmanNode::~HuffmanNode()
    {

    }
    
} // MZRTAD001
