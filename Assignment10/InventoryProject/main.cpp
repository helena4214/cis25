#include <iostream>
#include "Item.h"
using namespace std;

int main() { 
    Item item1("Beekgar", 110);
    Item item2("Mike Pence", 510);

    item1.display();
    item2.display();

    return 0;
}
