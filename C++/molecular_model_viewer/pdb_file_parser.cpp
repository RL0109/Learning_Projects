#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::ifstream, std::cout, std::cerr, std::cin, std::string;

class PDBFileParser {
    



};

int main() {
    //Open text file
    ifstream f("LEU.cif");

    if (!f.is_open()) {
        cerr << "Error opening the file!";
        return 1;

    }
    string s;   

    while (getline(f,s))
        cout << s << "\n";

    f.close();
    return 0;

}