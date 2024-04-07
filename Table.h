//
// Created by ryry8 on 5/24/2022.
//

#ifndef HUFFMAN_RILEYSUOMI_TABLE_H
#define HUFFMAN_RILEYSUOMI_TABLE_H
#include <istream>
#include "Letters.h"
#include <vector>
using std::istream;
using std::vector;

struct Table {
    vector<Letters> _vector; /// vector for creating table
//    Table& operator=(const Table& other); /// copy assignment op
    void ProcessInput(); /// creates the freq table
    void Sort(); /// sorts the freq table
    size_t Locate(Letters element);
    string ToString();
};


#endif //HUFFMAN_RILEYSUOMI_TABLE_H
