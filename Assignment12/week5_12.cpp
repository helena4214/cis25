#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std; 

// Struct to store relevant fields from one CSV row
struct BuildingEntry {
    string type;
    int year_built;
    double floor_area;
    double solar_potential;
    double carbon_reduction;
    string orientation;
};

// Class to read and parse a CSV file line by line
class CSVReader {
    ifstream file;  // File input stream

public:
    // Open file
    CSVReader(const string& filename) {
        file.open(filename);
    }

    // Read one line, split by comma into vector of strings
    bool readRow(vector<string>& cols) {
        string line;
        if (!getline(file, line)) return false;

        stringstream ss(line);
        string cell;
        cols.clear();

        while (getline(ss, cell, ',')) {
            cols.push_back(cell);
        }
        return true;
    }

    // Check if file actually opened
    bool isOpen() const {
        return file.is_open();
    }
};

int main() {
    string filename = "green_energy_dataset.csv";  // CSV file path
    CSVReader reader(filename); // CSV reader object

    if (!reader.isOpen()) {
        cerr << "Failed to open file.\n";
        return 1;
    }

    vector<string> row;
    reader.readRow(row);  // Skip header row

    vector<BuildingEntry> buildings;
    int count = 0;

    // Read up to 10 data rows
    while (reader.readRow(row) && count < 10) {
        if (row.size() < 14) continue;  // make sure row has enough columns

        BuildingEntry entry;
        entry.type = row[0];
        entry.year_built = stoi(row[1]); // Convert string to int
        entry.floor_area = stod(row[2]); // Convert string to double
        entry.orientation = row[3];
        entry.solar_potential = stod(row[6]);
        entry.carbon_reduction = stod(row[11]);

        buildings.push_back(entry);
        count++;
    }

    // Display the extracted info in readable format
    cout << "Building Data (first 10 rows):\n";
    for (const auto& b : buildings) {
        cout << "Type: " << b.type
             << ", Year: " << b.year_built
             << ", Area: " << b.floor_area << " m²"
             << ", Orientation: " << b.orientation
             << ", Solar Potential: " << b.solar_potential << " kWh/m²"
             << ", CO2 Reduction: " << b.carbon_reduction << "%\n";
    }

    return 0;
}
