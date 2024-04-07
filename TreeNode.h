//
// Created by ryry8 on 6/7/2022.
//

#ifndef HUFFMAN_RILEYSUOMI_TREENODE_H
#define HUFFMAN_RILEYSUOMI_TREENODE_H

#include "Letters.h"

struct Node  { /// creation of the nodes
    Letters data; /// pointer to letters
    Node* right = nullptr; /// pointer to right brother
    Node* left = nullptr; /// pointer to left kid
};


#endif //HUFFMAN_RILEYSUOMI_TREENODE_H
