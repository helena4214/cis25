#pragma once
#include <string>
using namespace std;

// Class representing a single pony with name and cutie mark
class Pony {
public:
    string name;
    string cutieMark;

    // constructor
    Pony(string n = "", string cm = "");

    // show pony info
    void display() const;
};
