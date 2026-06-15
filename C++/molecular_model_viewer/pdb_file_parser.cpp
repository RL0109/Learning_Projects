#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "raylib.h"


using std::ifstream, std::cout, std::cerr, std::cin, std::string, std::vector, std::stof;

struct Atom {
    Vector3 position;
    char elementId;

    Atom(Vector3 pos, char eId) {
        position = pos;
        elementId = eId;
    } 
};

// Will create class implementation once logic is discovered.
class PDBFileParser {
    
    public:
    struct Atom {
        Vector3 position;
        char elementId;

        Atom(Vector3 pos, char eId) {
            position = pos;
            elementId = eId;
        } 
    };



    vector<vector<string>> moleculedata;
    vector<string> columnHeader;
    vector<Vector3> coordinates;
    vector<Atom> atomData;

    PDBFileParser(ifstream &moleculeFile) {
        parseFile(moleculeFile);
        getCoordinates(moleculedata);
    }

    vector<string> lineParser(const string line) {

        vector<string> row;

        string str;

        std::stringstream ss(line);

        while (ss >> str) {
            row.push_back(str);
        }

        return row;
    } 

    void parseFile (ifstream &moleculeFile) {
        string line; 
        bool insideTargetLoop = false;
        bool finishedHeader = false;

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
                }
            }
        }
    }




    void readData (const vector<vector<string>> &dataVector) {

        for (auto dv : dataVector) {
            for (auto d : dv) {
                std::cout << d << " ";
            }
            cout << "\n";
        }

    }

    void getCoordinates(const vector<vector<string>> &dataVector) {
    
        for (int i = 1; i < dataVector[0].size(); i++ )
        {
            //Pull vector data from file
            Vector3 coordinates = {stof(dataVector[i][12]), stof(dataVector[i][13]), stof(dataVector[i][14])};
            //Pull element character from file
            char element = dataVector[i][1][0];
            //Applying coordinates and element to vector
            atomData.push_back(Atom(coordinates, element));
        }
    }


};


int main() {
    //Open text file
    ifstream molecularFile("LEU.cif");
    
    PDBFileParser parsedFile(molecularFile);

    for (int i = 0; i < parsedFile.atomData.size(); i++ ) {

        cout << parsedFile.atomData[i].position.x << " ";
        cout << parsedFile.atomData[i].position.y << " ";
        cout << parsedFile.atomData[i].position.z << "\n";

    }

    return 0;

}