//
// Created by ryry8 on 5/31/2022.
//

#ifndef HUFFMAN_RILEYSUOMI_TREE_H
#define HUFFMAN_RILEYSUOMI_TREE_H

#include <iostream>
#include "Table.h"
#include "Letters.h"
#include "TreeNode.h"


class Tree {
    Table _tree;
    Node* _root; /// need to keep track of the root
    vector<Letters> _table;
    void Encode(Node* node, string code, const Letters& key);
public:
    Tree();
    Tree(const Table& other); /// constructor of the tree
    void Create(); /// construction of tree
    void Encode(); /// encoding of the tree
    string EncodeTable()const; /// encoding tostring
//    string EncodeFile(Letters* let, Node* node); /// for a single character
    void BlowItUp(Node* ntd); /// look at arias code
    ~Tree(); /// look at arias example
    void Sort(vector<Node*>& element);
};


#endif //HUFFMAN_RILEYSUOMI_TREE_H
