/*
    This is the basic blobulator algorithm designed in C++.
    Intended for learning purposes only.
*/




#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>
#include <unordered_map>
#include "AminoScores.h"


class Blobulator 
{
    
    // Uses amino codes to get Kyte - Doolittle hydropathy scores
    void acquireValues () {
        for (auto aminoLetter: aminoCode) {
            hydroVal.push_back( KTNormalizedAminoScores[aminoLetter]);
        }
    }

    // Compares values between an amino's neighbors to see if the average 
    // is below the hydropathy threshold
    void averageValues ()
    {
        for (std::vector<float>::iterator it = hydroVal.begin(); it != hydroVal.end(); it++ ) 
            {
                if (it == hydroVal.begin()) {
                    hydroAvg.push_back((*it + *(it + 1)) / 2);
                    continue;
                }
                if (it == hydroVal.end()-1) {
                    hydroAvg.push_back((*(it - 1) + *it) / 2);
                    continue;
                }
                hydroAvg.push_back((*(it -1) + *it + *(it + 1))/3);
            }

        if (hydroAvg.size() != hydroVal.size()) {
            std::cout << "Vector lengths do not match!" << std::endl;
            std::cout << "HydroAverage Size: " << hydroAvg.size() << "\n" 
            << "HydroValue Size: " << hydroVal.size() << std::endl;
        }
    }

    // Populates the binary string with 0's for polar and 1's for hydrophobic
    void assignHydro () {
        for (auto value : hydroAvg) {
            if (value < hydropathy) {
                hydroBinary.push_back('0');
                } else {
                hydroBinary.push_back('1');
                }
        }
        if (hydroAvg.size() != hydroBinary.size()) {
            std::cout << "Vector lengths do not match!" << std::endl;
            std::cout << "HydroAverage Size: " << hydroAvg.size() << "\n" 
            << "hydroBinary Size: " << hydroBinary.size() << std::endl;
        }
        hydroCharacter = hydroBinary; // Created copy for string mutation
    }   

    //Check binary string if enough contiguous hydrophobic amino's match or pass the 
    // length minimum.
    void determineHblobs () {
        auto n = hydroCharacter.size();
        int i = 0;
        int hlength = 0;
        int plength = 0;
        int start = 0;
        while (i < n) {
            if (hydroCharacter[i] != '0' && hlength < 1) {
                start = i;
            } 
            if (hydroCharacter[i] != '0') {
                ++hlength;
            }

            if ((hydroCharacter[i] == '0' || i == n-1) && hlength > length - 1) {
                int end = start + hlength;
                for (int j = start; j != end; j++) {
                    hydroCharacter[j] = 'h';
                }
                hlength = 0;
            
            
            } 
            if (hydroCharacter[i] == '0' && hlength < length) {
                hlength = 0;
            }
            ++i;
        }

    }

    // Looks for consecutive 0's that pass the length min.
    // Failure marks the character for s as in short
    void determinePblobs () {
        auto n = hydroCharacter.size();
        int i = 0;
        int plength = 0;
        int start = 0;

        while (i < n) {
            if (hydroCharacter[i] != 'h') {
                if (plength == 0) {
                    start = i;
                }
                ++plength;
            }           

            if ((hydroCharacter[i] == 'h' || i == n-1) && plength > 0) {
                if (plength > length - 1) {
                    int end = plength + start;
                    for (int j = start; j != end; j++) {
                        hydroCharacter[j] = 'p';
                    }
                    plength = 0;
                } else if (plength < length) {
                    int end = plength + start;
                    for (int j = start; j != end; j++) {
                        hydroCharacter[j] = 's';
                    }
                    plength = 0;
                }
            
            }
            i++;
        
        }

        if (hydroCharacter.size() != hydroBinary.size() ) {
            std::cout << "Sizes do not match!" << "\nHydro Binary Size: "
            << hydroBinary.size() << "\nHydro Average Size: "  <<
            hydroAvg.size() << "\n";
            }
    }



    public:
        std::string aminoCode;
        std::string hydroBinary;
        std::string hydroCharacter;
        std::vector<float> hydroVal;
        std::vector<float> hydroAvg;
        int length;
        float hydropathy; 

    // Blobulator Constructor
    Blobulator(std::string aC, int l, float h) {
        aminoCode = aC;
        length = l;
        hydropathy = h;

        acquireValues();
        averageValues();
        assignHydro();
        determineHblobs(); 
        determinePblobs();
    }

    

    // Helper functions 
    
    
    // Counts the number of hydrophobic amino acids
    int HBlobCount() {
        int i = 0;
        int hNumber = 0;
        while (i < hydroBinary.size()) {
            if (hydroBinary[i] == '1')
                hNumber++;
            i++;
        }
        return hNumber;

    }



    




    // Creating operator overloads to compare Blobulator Objects

    bool operator<(Blobulator blob2) {
        if (this->HBlobCount() < blob2.HBlobCount())
            return true;
        else 
            return false;
    }

    bool operator>(Blobulator blob2) {
        if (this-> HBlobCount() > blob2.HBlobCount())
            return true;
        else
            return false;
    }


    // No dynamically allocated memory so no deconstructor needed
};




int main() {
    std::string aminoCode;
    float hydropathy;
    int length;
    
    std::cout << "Please Input a FASTA Sequence (Human Amino Acids Only):";
    std::cin >> aminoCode;
    std::cout << "\nPlease Input Hydropathy Minimum (0.0 - 1.0):";
    std::cin >> hydropathy;
    std::cout << "\nPlease Input Length Minimum (0 - Sequence Length):";
    std::cin >> length;
    std::cout << "\n";

    // Demonstrates the difference between sequence, binary, and characters.
    Blobulator blob(aminoCode, length, hydropathy);
    std::cout << "Blobulated!\n" 
    << "Comparing Sequence to Binary to Blobs\n----------------\n"
    << "Sequence: " << blob.aminoCode 
    << "\n----------------\nBinary: " << blob.hydroBinary 
    <<"\n----------------\nBlob Assignment: " 
    << blob.hydroCharacter << "\n\n";
    system("pause");
}