#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "raylib.h"
#include "atom.h"

using std::ifstream, std::cout, std::cerr, std::cin, std::string, std::vector;

class PDBFileParser {
    



};

vector<string> lineParser(const string line) {

    vector<string> row;

    string str;

    std::stringstream ss(line);

    while (ss >> str) {
        cout << "string steam: " << str << "\n";
        row.push_back(str);
    }

    return row;
} 

void readData (const vector<vector<string>> dataVector) {

    for (auto dv : dataVector) {
        for (auto d : dv) {
            std::cout << d << " ";
        }
        cout << "\n";
    }

}


int main() {
    //Open text file
    ifstream moleculeFile("LEU.cif");
    string line; 

    bool insideTargetLoop = false;
    int columnCount = 0;
    bool finishedHeader = false;

    vector<vector<string>> moleculedata;
    vector<string> columnHeader;
    vector<Vector3> coordinates;


    while (std::getline(moleculeFile , line)) {
        if (line.rfind("_chem_comp_atom.comp_id", 0) == 0) {
            insideTargetLoop = true;
        }
        
        if (insideTargetLoop && !line.empty()) {
            if (line[0] == '_') {
                columnHeader.push_back(line);
            }
            if (line[0] != '_') {
                if (!finishedHeader) {
                    moleculedata.push_back(columnHeader);
                    finishedHeader = true;
                }
                if (line[0] == '#') {
                    break;
                }
                moleculedata.push_back(lineParser(line));
                cout << line << "\n";
            }
        }
    }
      
    cout << "Reading data" << "\n";
    readData(moleculedata);
    cout << moleculedata[0][12];
    cout << moleculedata[0][13];
    cout << moleculedata[0][14];

    moleculeFile.close();
    return 0;

}