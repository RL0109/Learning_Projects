#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <unordered_map>
#include "AminoScores.h"


class Blobulator 
{
    public:

    struct blobData // There is no difference between classes and structs, this
    // just seperates the data from the functions.
    {
        std::string aminoCode;
        std::string hydroCheck; // Sanity check
        std::string hydroBinary;
        std::vector<float> hydroVal;
        std::vector<float> hydroAvg;
        int length;
        float hydropathy; 

    };

    blobData data; // Initialize data type

    void acquireValues (std::string& aaCode) {
        for (auto aminoLetter: aaCode) {
            data.hydroVal.push_back( KTNormalizedAminoScores[aminoLetter]);
        }
    }

    void averageValues (std::vector<float>& hydroValue)
    {
        for (std::vector<float>::iterator it = hydroValue.begin(); it != hydroValue.end(); it++ ) 
            {
                if (it == hydroValue.begin()) {
                    data.hydroAvg.push_back((*it + *(it + 1)) / 2);
                    continue;
                }
                if (it == hydroValue.end()-1) {
                    data.hydroAvg.push_back((*(it - 1) + *it) / 2);
                    continue;
                }
                data.hydroAvg.push_back((*(it -1) + *it + *(it + 1))/3);
            }

        if (data.hydroAvg.size() != data.hydroVal.size()) {
            std::cout << "Vector lengths do not match!" << std::endl;
            std::cout << "HydroAverage Size: " << data.hydroAvg.size() << "\n" 
            << "HydroValue Size: " << data.hydroVal.size() << std::endl;
        }
    }

    void assignHydro (std::vector<float>& hydroAverage) {
        for (auto value : data.hydroAvg) {
            if (value < data.hydropathy) {
                data.hydroCheck.push_back('0');
                } else {
                data.hydroCheck.push_back('1');
                }
        }
        if (data.hydroAvg.size() != data.hydroCheck.size()) {
            std::cout << "Vector lengths do not match!" << std::endl;
            std::cout << "HydroAverage Size: " << data.hydroAvg.size() << "\n" 
            << "HydroCheck Size: " << data.hydroCheck.size() << std::endl;
        }
        data.hydroBinary = data.hydroCheck; // Assigned for sanity checking
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

            if ((hydroBinary[i] == '0' || i == n-1) && hlength > data.length - 1) {
                int end = start + hlength;
                for (int j = start; j != end; j++) {
                    hydroBinary[j] = 'h';
                }
                hlength = 0;
            
            
            } 
            if (hydroBinary[i] == '0' && hlength < data.length) {
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
                if (plength > data.length - 1) {
                    int end = plength + start;
                    for (int j = start; j != end; j++) {
                        hydroBinary[j] = 'p';
                    }
                    plength = 0;
                } else if (plength < data.length) {
                    int end = plength + start;
                    for (int j = start; j != end; j++) {
                        hydroBinary[j] = 's';
                    }
                    plength = 0;
                }
            
            }
            i++;
        
        }

        if (hydroBinary.size() != data.hydroAvg.size() ) {
            std::cout << "Sizes do not match!" << "\nHydro Binary Size: "
            << hydroBinary.size() << "\nHydro Average Size: "  <<
            data.hydroAvg.size() << "\n";
            }
    }
};




int main() {
    Blobulator blob;
    
    std::cout << "Please Input a FASTA Sequence:";
    std::cin >> blob.data.aminoCode;
    std::cout << "\nPlease Input Hydropathy Minimum:";
    std::cin >> blob.data.hydropathy;
    std::cout << "\nPlease Input Length Minimum:";
    std::cin >> blob.data.length;
    std::cout << "\n";
    
    blob.acquireValues(blob.data.aminoCode);
    blob.averageValues(blob.data.hydroVal);
    blob.assignHydro(blob.data.hydroAvg);
    blob.determineHblobs(blob.data.hydroBinary); 
    blob.determinePblobs(blob.data.hydroBinary);
    std::cout << "Blobulated!\n" << "Comparing Sequence to Binary to Blobs\n----------------\n"
    << "Sequence: " << blob.data.aminoCode
    << "\n----------------\nBinary: " << blob.data.hydroCheck 
    <<"\n----------------\nBlob Assignment: " << blob.data.hydroBinary << "\n" 
    <<std::endl;
    system("pause");
}