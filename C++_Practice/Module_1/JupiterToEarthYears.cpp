#include <iostream>

float jupiterToEarth (float year) {
    return year * 12;
}

int main() {

    float jupiterYear;

    while (std::cin >> jupiterYear) {
        std::cout << jupiterToEarth(jupiterYear) << std::endl;
    } 

}