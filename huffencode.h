#ifndef HUFFENCODE_H
#define HUFFENCODE_H

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "HuffmanTree.h"

namespace MZRTAD001{

    bool loadTextFile(std::string fileName,std::vector<std::string>& textLines);
    void getFrequencies(std::vector<std::string>& textLines, std::unordered_map<char,int>& charFreqMap);
    
}

#endif