#pragma once
#include "Pony.h"

// Class for managing a collection of Pony objects
class PonyManager {
    Pony** ponies;  // pointer to array of Pony pointers
    int capacity;   // max number of ponies allowed
    int count;      // current number of ponies

public:
    PonyManager(int size);     // Constructor
    ~PonyManager();            // Destructor to clean up memory

    void addPony(const string& name, const string& cutieMark); // add a pony
    void displayAll() const;   // show all ponies
    void saveToFile(const string& filename) const; // write ponies to a file
    void loadFromFile(const string& filename);     // load ponies from a file
    int binarySearch(const string& target);        // binary search by name
    void sortByName();         // sort ponies alphabetically
};
