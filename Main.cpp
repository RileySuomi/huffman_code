//
// Created by ryry8 on 5/24/2022.
//
#include "Table.h"
#include "Letters.h"
#include "Tree.h"
#include "Node.h"
#include <iostream>

#include <string>

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cin;


int main() {
    Table table;

    table.ProcessInput();
    table.Sort();

    cout << table.ToString() << endl;

    Tree tree(table);
    tree.Create();
    cout << endl;
    tree.Encode();
    cout << endl << tree.EncodeTable();
}
