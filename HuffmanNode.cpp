//HuffmanNode
//Models huffmann node of each huffman tree

#include "HuffmanNode.h"

using namespace std;

namespace MZRTAD001{

    //Constructors
    HuffmanNode::HuffmanNode(char charctr, int freq, std::shared_ptr<HuffmanNode> lhs, std::shared_ptr<HuffmanNode> rhs )
        :character(charctr ), frequency(freq), left(lhs), right(rhs) { }
    
    HuffmanNode::HuffmanNode(char charctr, int freq)
        :character(charctr), frequency(freq), left(nullptr), right(nullptr)  { }

    //Copy Constructor
    HuffmanNode::HuffmanNode(HuffmanNode& other )
        :character(other.getCharacter()),frequency(other.getFrequency()),
         left(other.getLeft()), right(other.getRight()) { }

    //Move Constructor
    HuffmanNode::HuffmanNode(HuffmanNode&& oldNode)
        :character(oldNode.getCharacter()),frequency(oldNode.getFrequency()),
         left(oldNode.getLeft()), right(oldNode.getRight()) 
    {
        oldNode.left = nullptr;
        oldNode.right = nullptr;
    }

    //Destructor
    HuffmanNode::~HuffmanNode(){
        left = nullptr;
        right = nullptr;
    }

    //return the frequecny of a character
    int HuffmanNode::getFrequency(){
        return frequency;
    }

    //returns the character contained in the node
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

