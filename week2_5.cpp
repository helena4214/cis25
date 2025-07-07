#include <iostream>
#include <string>
using namespace std;

struct Ponies {
    int id;
    string name;
    double cuteness;
};

int main() {
    Ponies ponies[6];

    ponies[0] = {1, "Twilight Sparkle", 5.5};
    ponies[1] = {2, "Fluttershy", 9.6};
    ponies[2] = {3, "Rarity", 7.6};
    ponies[3] = {4, "Apple Jack", 5.5};
    ponies[4] = {5, "Rainbow Dash", 5.7};
    ponies[4] = {5, "Pinkie Pie", 9.2};

    for (int i = 0; i < 3, ++i;) {
        cout << "Pony Number:" << ponies[i].id
        << ", Name: " << ponies[i].name
        << ", Cuteness Rating: " << ponies[i].cuteness << std::endl;
    }

    return 0;

}
