#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pony {
    public:
        string name;
        int power_level;


   void saveToFile() { 
       ofstream out("ponies.txt"); 
       if (out.is_open()) { 
           out << name << "," << power_level << endl; 
           out.close(); 
           cout << "Pony saved to file." << endl; 
       } else { 
           cout << "Unable to open file for writing." << endl; 
       } 
   }


   void loadFromFile() { 
       ifstream in("ponies.txt"); 
       if (in.is_open()) { 
           string line; 
           while (getline(in, line)) { 
               cout << "File content: " << line << endl; 
           } 
           in.close(); 
       } else { 
           cout << "Unable to open file for reading." << endl; 
       } 
    }
};

int main() { 
  Pony pony; 
   pony.name = "Celestia"; 
   pony.power_level = 10; 
 
   pony.saveToFile(); 
   pony.loadFromFile(); 
   return 0; 
}
