#include <iostream>
using namespace std;
int main() {
	int choice;
	cout << "1. Add Item\n2. View Items\n3. Exit\n";
	cout << "Choose an option: ";
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "Item added!\n";
			break;
		case 2:
			cout << "Displaying items...\n";
			break;
		case 3:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid option.\n";
	}
	return 0;
}
