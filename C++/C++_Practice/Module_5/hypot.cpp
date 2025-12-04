/*
    Project 5-2
    Create a hypoteneuse function
*/
#include <iostream>
#include <string>
#include <cmath>

double hypot(double a, double b) {

    return std::sqrt((a*a) + (b*b));
} 

int main() {

    double A = 5.0;
    double B = 3.0;

    double hyp = hypot(A,B);

    std::cout << "Hypoteneuse is: " << hyp;

    return 0;
}