#ifndef HUFFENCODE_H
#define HUFFENCODE_H

#include <fstream>
#include <iostream>
#include <string>
#include "HuffmanTree.h"

namespace MZRTAD001{

    bool loadTextFile(std::string fileName,std::vector<std::string>& textLines);
    void getFrequencies(std::vector<std::string>& textLines, std::unordered_map<char,int>& charFreqMap);
    
}

#endif