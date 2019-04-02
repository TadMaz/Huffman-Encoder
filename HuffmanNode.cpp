//HuffmanNode
//Models huffmann node of each huffman tree

#include "HuffmanNode.h"

using namespace std;

namespace MZRTAD001{

   
    HuffmanNode::HuffmanNode(char charctr, int freq, std::shared_ptr<HuffmanNode> lhs, std::shared_ptr<HuffmanNode> rhs )
        :character(charctr ), frequency(freq), left(lhs), right(rhs) { }
    
    HuffmanNode::HuffmanNode(char charctr, int freq)
        :character(charctr), frequency(freq), left(nullptr), right(nullptr)  { }

    int HuffmanNode::getFrequency(){
        return frequency;
    }

    char HuffmanNode::getCharacter(){
        return character;
    }

    std::shared_ptr<HuffmanNode> HuffmanNode::getLeft(){
        return left;
    }

    std::shared_ptr<HuffmanNode> HuffmanNode::getRight(){
        return right;
    }

    void HuffmanNode::setLeft(std::shared_ptr<HuffmanNode> lhs){
        left = lhs;
    }
    
    void HuffmanNode::setRight(std::shared_ptr<HuffmanNode> rhs){
        right = rhs;
    }
}

