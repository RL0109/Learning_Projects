#include <iostream> 
#include <vector>
#include <cmath>


int main () {

    std::vector<float> values;
    float value;
    float average = 0;
    while (std::cin >> value) {
        if (values.size() == 4) {
            values.push_back(value);
            break;
        }
        values.push_back(value);
    }
    for (std::vector<float>::iterator it = values.begin(); it != values.end(); it++) {
        average += std::abs(*it);
    }
    average /= 5;

    std::cout <<"Average of Abosulute Values: "<< average << std::endl; 

}