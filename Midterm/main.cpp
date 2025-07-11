#include "PonyManager.h"
#include <iostream>
using namespace std;

int main() {
    PonyManager manager(10); // create a PonyManager that can hold up to 10 ponies

    // Add some sample ponies
    manager.addPony("Twilight Sparkle", "Magic");
    manager.addPony("Rainbow Dash", "Rainboom");
    manager.addPony("Pinkie Pie", "Laughter");

    // Sort the list for binary search to work
    manager.sortByName();

    // Show all ponies
    manager.displayAll();

    // Save the pony list to a file
    cout << "\nSaving to ponies.txt..." << endl;
    manager.saveToFile("ponies.txt");

    // Search for a pony
    cout << "\nSearching for Rainbow Dash..." << endl;
    int index = manager.binarySearch("Rainbow Dash");
    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not found." << endl;

    // Show memory size of a Pony
    cout << "\nSize of Pony object: " << sizeof(Pony) << " bytes" << endl;

    return 0;
}
