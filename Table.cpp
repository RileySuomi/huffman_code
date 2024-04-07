//
// Created by ryry8 on 5/24/2022.
//

#include "Table.h"
#include "Letters.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using std::fstream;
using std::cout;
using std::endl;
using std::cin;
using std::stringstream;
using std::sort;
using std::reverse;

void Table::ProcessInput() {
    string file;
    string text;
    fstream inFs;
    char letter;
//    cout << "Enter name of file you want to open: ";
//    cin >> file;
    inFs.open("../test-file-1.txt");
//    while (!inFs.is_open()) {
//        cout << file << " doesn't open" << endl;
//        cout << "Enter new file name: ";
//        cin >> file;
//        inFs.open(file);
//    }
    if (inFs.is_open()) {
        while (inFs.get(letter)) {
                bool known = false;
                if (letter == '\r') { /// this is return character
                    text = "CR";
                }
                else if (letter == '\n') { /// in case where we need LF
                    text = "LF";
                }
                else if (letter == ' ') {
                    text = " ";
                }
                else {
                    text = letter;
                }
                for (auto & i : _vector) { /// auto adjusts to what I need
                    if (i.GetLetter() == text) { /// exist
                        i.AddFrequency();
                        known = true;
                        break;
                    }
                }
                if (!known) {
                    _vector.push_back(text); /// throw the letter in the vector
                }
        }
    }
    inFs.close();
}

void Table::Sort() {
    sort(_vector.begin(), _vector.end());
    reverse(_vector.begin(), _vector.end());
}

//
//Table &Table::operator=(const Table &other) {
//    if (this != &other) {
//        this->_vector.clear();
//        for (size_t i = 0; i < other._vector.size(); ++i) {
//            _vector.push_back(other._vector.at(i));
//        }
//    }
//    return *this;
//}


string Table::ToString() {
    stringstream retVal;
    for (auto & letters : _vector) {
        retVal << letters.ToString() << endl;
    }
    return retVal.str();
}

size_t Table::Locate(Letters element) {
    for (size_t i = 0; i < _vector.size(); ++i) {
        if (_vector.at(i).GetLetter() == element.GetLetter()) {
            return i;
        }
    }
    return -1;
}
