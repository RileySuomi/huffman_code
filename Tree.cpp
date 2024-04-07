//
// Created by ryry8 on 5/31/2022.
//

#include "Tree.h"
#include "Table.h"
#include "Letters.h"
#include <algorithm>
#include <sstream>
#include <utility>

using std::stringstream;


Tree::Tree() : _root(nullptr) {}

Tree::~Tree() {
    if (_root) {
        BlowItUp(_root);
    }
}

Tree::Tree(const Table &other) : _root(nullptr), _tree(other) {}

void Tree::Create() {
    vector<Node*> element; /// vector to store the trees elements
    for (auto & i : _tree._vector) {
        Node* neo = new Node;
        neo->data.SetLetter(i.GetLetter());
        neo->data.SetFrequency(i.GetFrequency());
        neo->left = nullptr;
        neo->right = nullptr;
        element.push_back(neo);
    }
    while (element.size() > 1) { /// as long as vector has elements still
        Node* parent = new Node;
        parent->left = element.back(); // left to be last thing in vector
//        std::cout << parent->left->data.GetLetter() << std::endl;
//        std::cout << parent->data.GetFrequency() << std::endl;
        element.pop_back(); // delete last in vector
        parent->right = element.back(); // right bro to be next element at end
//        std::cout << parent->right->data.GetLetter() << std::endl;
//        std::cout << parent->right->data.GetFrequency() << std::endl;
        element.pop_back(); // delete last in vector
        /// parent should be both kids added together
        parent->data.SetLetter(parent->left->data.GetLetter() + parent->right->data.GetLetter());
    //    std::cout << parent->data.GetLetter() << std::endl;
        parent->data.SetFrequency(parent->left->data.GetFrequency() + parent->right->data.GetFrequency());
    //    std::cout << parent->data.GetFrequency() << std::endl;
        /// push the parent back into the vector
        element.push_back(parent);
    //    std::cout << parent << std::endl;
        /// resort the vector, should make sure thing pushed goes back to correct spot
        Sort(element);
    }
    _root = element.back();
}

bool Comparable(Node* l, Node* r) {
    if (l->data.GetFrequency() == r->data.GetFrequency()) {
        return (l->data.GetLetter() > r->data.GetLetter());
    }
    else {
        return l->data.GetFrequency() > r->data.GetFrequency();
    }
}

void Tree::Sort(vector<Node*>& element) { /// helper
    sort(element.begin(), element.end(), Comparable);
}


void Tree::Encode(Node* node, string code, const Letters& key) {
    while (node->left != nullptr && node->right != nullptr) {
        if (node->left != nullptr && node->left->data.GetLetter().find(key.GetLetter()) != string::npos) {
            node = node->left;
            code.append("1");
        }
        if (node->right != nullptr && node->right->data.GetLetter().find(key.GetLetter()) != string::npos) {
            node = node->right;
            code.append("0");
        }
    }
    size_t keyNum;
    keyNum = _tree.Locate(key);
    _tree._vector.at(keyNum)._code = code;
    code = "";
}

void Tree::Encode() {
    string code;
    Letters key;
    for (size_t i = 0; i < _tree._vector.size(); ++i) {
        key = _tree._vector.at(i);
        Encode(_root, code, key);
    }
}

string Tree::EncodeTable() const {
    stringstream retVal;
    for (auto & elements : _tree._vector) {
        if (elements.GetLetter() == "CR" || elements.GetLetter() == "LF") {
            retVal << "{key: " << elements.GetLetter() << ", code: " << elements._code << "}" << std::endl;
        }
        else{
            retVal << "{key:  " << elements.GetLetter() << ", code: " << elements._code << "}" << std::endl;
        }
    }
    return retVal.str();
}

void Tree::BlowItUp(Node* ntd) {
    if (ntd->left) {
        BlowItUp(ntd->left);
    }
    if (ntd->right) {
        BlowItUp(ntd->right);
    }
///    delete ntd->data; (doesnt like this)
    delete ntd;
}




