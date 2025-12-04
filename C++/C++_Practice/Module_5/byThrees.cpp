/*
    Project 5-4
    Demonstrating global variables and void functions
*/
#include <iostream>

int num = 0;

void byThrees() {
    num += 3;
}

void reset() {
    num = 0;
}

int main() {

    int max = 5;

    for (int i = 0; i != max; i++) {
        byThrees();
        std::cout << "Current number: " << num << "\n";
    }

    reset();

    std::cout << "Number is reset: " << num << "\n";


    return 0;
}