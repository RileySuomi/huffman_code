//
// Created by ryry8 on 5/24/2022.
//

#ifndef HUFFMAN_RILEYSUOMI_LETTERS_H
#define HUFFMAN_RILEYSUOMI_LETTERS_H

#include <iostream>
#include <string>
//#include "Node.h"
//#include "TreeNode.h"

using std::string;

class Letters {
private:
    string _letter;
    size_t _frequency;
public:
    string _code;
    Letters();
    Letters(const Letters& given);
    Letters(string encode, string letter);
    Letters(string &letter, size_t frequency = 1);
    string ToString()const;
    size_t GetFrequency()const; /// keeps track of frequency
    void AddFrequency(); /// adds one to frequency
    void SetFrequency(const size_t& freq);
    string GetLetter()const;
    void SetLetter(string letter);
    bool operator<(const Letters &letters);
};


#endif //HUFFMAN_RILEYSUOMI_LETTERS_H
