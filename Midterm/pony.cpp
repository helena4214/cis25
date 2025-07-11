#include "Pony.h"
#include <iostream>
using namespace std;

// Constructor implementation
Pony::Pony(string n, string cm) : name(n), cutieMark(cm) {}

// Print pony's name and cutie mark
void Pony::display() const {
    cout << name << " - Cutie Mark: " << cutieMark << endl;
}
