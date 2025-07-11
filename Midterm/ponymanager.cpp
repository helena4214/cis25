#include "PonyManager.h"
#include <fstream>
#include <iostream>
using namespace std;

// Constructor starts dynamic array
PonyManager::PonyManager(int size) : capacity(size), count(0) {
    ponies = new Pony*[capacity];
}

// Destructor gets rid of all Pony objects and the array
PonyManager::~PonyManager() {
    for (int i = 0; i < count; ++i)
        delete ponies[i];
    delete[] ponies;
}

// Adds a new Pony to the list
void PonyManager::addPony(const string& name, const string& cutieMark) {
    if (count >= capacity) {
        cout << "List full!" << endl;
        return;
    }
    ponies[count++] = new Pony(name, cutieMark);
}

// Prints all ponies
void PonyManager::displayAll() const {
    for (int i = 0; i < count; ++i)
        ponies[i]->display();
}

// Saves all pony data to a text file
void PonyManager::saveToFile(const string& filename) const {
    ofstream out(filename);
    for (int i = 0; i < count; ++i)
        out << ponies[i]->name << "," << ponies[i]->cutieMark << endl;
    out.close();
}

// Loads ponies from a file (expects Name,CutieMark format)
void PonyManager::loadFromFile(const string& filename) {
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        size_t comma = line.find(',');
        if (comma != string::npos)
            addPony(line.substr(0, comma), line.substr(comma + 1));
    }
    in.close();
}

// use binary search to search for a pony by name
int PonyManager::binarySearch(const string& target) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (ponies[mid]->name == target)
            return mid;
        else if (ponies[mid]->name < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

// Sorts ponies alphabetically by name using bubble sort
void PonyManager::sortByName() {
    for (int i = 0; i < count - 1; ++i)
        for (int j = 0; j < count - i - 1; ++j)
            if (ponies[j]->name > ponies[j + 1]->name)
                swap(ponies[j], ponies[j + 1]);
}
