#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <unordered_map>
#include "AminoScores.h"


class Blobulator 
{
    public:
        std::string aminoCode;
        std::string hydroCheck; // Sanity check
        std::string hydroBinary;
        std::vector<float> hydroVal;
        std::vector<float> hydroAvg;
        int length;
        float hydropathy; 

    

    void acquireValues (std::string& aaCode) {
        for (auto aminoLetter: aaCode) {
            hydroVal.push_back( KTNormalizedAminoScores[aminoLetter]);
        }
    }

    void averageValues (std::vector<float>& hydroValue)
    {
        for (std::vector<float>::iterator it = hydroValue.begin(); it != hydroValue.end(); it++ ) 
            {
                if (it == hydroValue.begin()) {
                    hydroAvg.push_back((*it + *(it + 1)) / 2);
                    continue;
                }
                if (it == hydroValue.end()-1) {
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

    void assignHydro (std::vector<float>& hydroAverage) {
        for (auto value : hydroAvg) {
            if (value < hydropathy) {
                hydroCheck.push_back('0');
                } else {
                hydroCheck.push_back('1');
                }
        }
        if (hydroAvg.size() != hydroCheck.size()) {
            std::cout << "Vector lengths do not match!" << std::endl;
            std::cout << "HydroAverage Size: " << hydroAvg.size() << "\n" 
            << "HydroCheck Size: " << hydroCheck.size() << std::endl;
        }
        hydroBinary = hydroCheck; // Assigned for sanity checking
    }   

    void determineHblobs (std::string& hydroBinary) {
        auto n = hydroBinary.size();
        int i = 0;
        int hlength = 0;
        int plength = 0;
        int start = 0;
        while (i < n) {
            if (hydroBinary[i] != '0' && hlength < 1) {
                start = i;
            } 
            if (hydroBinary[i] != '0') {
                ++hlength;
            }

            if ((hydroBinary[i] == '0' || i == n-1) && hlength > length - 1) {
                int end = start + hlength;
                for (int j = start; j != end; j++) {
                    hydroBinary[j] = 'h';
                }
                hlength = 0;
            
            
            } 
            if (hydroBinary[i] == '0' && hlength < length) {
                hlength = 0;
            }
            ++i;
        }

    }

    void determinePblobs (std::string& hydroBinary) {
        auto n = hydroBinary.size();
        int i = 0;
        int plength = 0;
        int start = 0;

        while (i < n) {
            if (hydroBinary[i] != 'h') {
                if (plength == 0) {
                    start = i;
                }
                ++plength;
            }           

            if ((hydroBinary[i] == 'h' || i == n-1) && plength > 0) {
                if (plength > length - 1) {
                    int end = plength + start;
                    for (int j = start; j != end; j++) {
                        hydroBinary[j] = 'p';
                    }
                    plength = 0;
                } else if (plength < length) {
                    int end = plength + start;
                    for (int j = start; j != end; j++) {
                        hydroBinary[j] = 's';
                    }
                    plength = 0;
                }
            
            }
            i++;
        
        }

        if (hydroBinary.size() != hydroAvg.size() ) {
            std::cout << "Sizes do not match!" << "\nHydro Binary Size: "
            << hydroBinary.size() << "\nHydro Average Size: "  <<
            hydroAvg.size() << "\n";
            }
    }
};




int main() {
    Blobulator blob;
    
    std::cout << "Please Input a FASTA Sequence:";
    std::cin >> blob.aminoCode;
    std::cout << "\nPlease Input Hydropathy Minimum:";
    std::cin >> blob.hydropathy;
    std::cout << "\nPlease Input Length Minimum:";
    std::cin >> blob.length;
    std::cout << "\n";
    
    blob.acquireValues(blob.aminoCode);
    blob.averageValues(blob.hydroVal);
    blob.assignHydro(blob.hydroAvg);
    blob.determineHblobs(blob.hydroBinary); 
    blob.determinePblobs(blob.hydroBinary);
    std::cout << "Blobulated!\n" << "Comparing Sequence to Binary to Blobs\n----------------\n"
    << "Sequence: " << blob.aminoCode
    << "\n----------------\nBinary: " << blob.hydroCheck 
    <<"\n----------------\nBlob Assignment: " << blob.hydroBinary << "\n" 
    <<std::endl;
    system("pause");
}