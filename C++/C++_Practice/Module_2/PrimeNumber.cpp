#include <iostream>
#include <cmath>

using namespace std;

int main () {

    for (int i = 2; i < 101; i++) {
        bool isPrime = true;
        for (int j = 2; j < (int)sqrt(i) + 1; j++) {
            if (i % j == 0) {
                cout << i << " is not prime" << "\n";
                isPrime = false;
                break;
            } 
        }
        if (isPrime == true) {
            cout << i << " is prime" << "\n";
        }

    }
    
    
    
    return 0;
}