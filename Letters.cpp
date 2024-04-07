//
// Created by ryry8 on 5/24/2022.
//

#include "Letters.h"
#include <sstream>
#include <utility>
using std::cout;
using std::endl;
using std::stringstream;

Letters::Letters() : _frequency(1){ /// default ctor
}

Letters::Letters(const Letters& given) {
    this->_frequency = given._frequency;
    this->_letter = given._letter;
}

Letters::Letters(string &letter, size_t frequency) :_letter(letter), _frequency(frequency) {}

void Letters::SetFrequency(const size_t &freq) {
    _frequency = freq;
}

size_t Letters::GetFrequency() const { /// getter for frequency
    return _frequency;
}

void Letters::AddFrequency() { /// adds 1 to frequency
    _frequency++;
}

string Letters::GetLetter() const { /// getter for letter
    return _letter;
}

void Letters::SetLetter(const string letter) {
    _letter = letter;
}

bool Letters::operator<(const Letters &letters) {
    if (GetFrequency() == letters.GetFrequency()) { /// same frequency need check letter
        if (GetLetter() < letters.GetLetter()) {
            return true;
        }
        return false;
    }
    else if (GetFrequency() < letters.GetFrequency()) {
        return true;
    }
    else{
        return false;
    }
}
string Letters::ToString() const {
    stringstream retVal;
    if (_letter == "CR" || _letter == "LF") {
        retVal << "{Element: " << _letter << ", frequency: " << _frequency << "}";
    }
    else{
        retVal << "{Element:  " << _letter << ", frequency: " << _frequency << "}";
    }

    return retVal.str();
}

Letters::Letters(string encode, string letter) : _letter(std::move(letter)), _code(std::move(encode)) {}

