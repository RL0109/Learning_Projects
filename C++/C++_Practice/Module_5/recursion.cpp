/*
    Project 5-6
    Recursive Exercise
*/
#include <iostream>

int max = 10;

int count(int a) {
    if (a == max + 1) {
        return a;
    }
    std::cout << a << "\n";

    return count(a+1);

}

int main() {

    int i = 0;

    count(i);


}