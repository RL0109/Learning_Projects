/*
    Project 6-3
    Round a double into an int
*/
#include <iostream>
#include <cmath>


void Round(double& d);

int main() {
    double* p;
    double d = 10.6;

    Round(d);

    std::cout << d << "\n";


}

void Round(double& d) 
{
    double frac;
    double val;
    frac = modf(d, &val);

    if (frac < .5) d = val;
    else d = val +1;
}