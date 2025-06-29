#include <iostream>
using namespace std;

// Abstract base class: Pony
class Pony {
public:
    string name;
    int sassiness;

    Pony(string n, int s) {
        name = n;
        sassiness = s;
    }

    virtual void display() = 0;
};


class Unicorn : public Pony {
public:
    Unicorn(string n, int s) : Pony(n, s) {}

    void display() override {
        cout << name << " Unicorn, Sassiness: " << sassiness << endl;
    }
};

class EarthPony : public Pony {
public:
    EarthPony(string n, int s) : Pony(n, s) {}

    void display() override {
        cout << name << " Earth Pony, Sassiness: " << sassiness << endl;
    }
};

int main() {
    Pony* p1 = new Unicorn("Twilight Sparkle", 95);
    Pony* p2 = new EarthPony("Applejack", 40);

    p1->display();
    p2->display();

    delete p1;
    delete p2;

    return 0;
}
