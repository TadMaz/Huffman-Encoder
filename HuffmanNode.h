//Huffman Node

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <memory>
// a class representing a Huffman Tree node

namespace MZRTAD001{

    class HuffmanNode
    {
    private:
        char character;
        int frequency;
        std::shared_ptr<HuffmanNode> left;
        std::shared_ptr<HuffmanNode> right; 

    public:
        HuffmanNode(char charctr, int freq, std::shared_ptr <HuffmanNode> lhs, std::shared_ptr<HuffmanNode> rhs  );
        
        HuffmanNode(char charctr, int freq);
        
        int getFrequency();

        char getCharacter();

        std::shared_ptr<HuffmanNode> getLeft();

        std::shared_ptr<HuffmanNode> getRight();

        void setLeft(std::shared_ptr<HuffmanNode> rhs);

        void setRight(std::shared_ptr<HuffmanNode> rhs);
    };

}
#endif