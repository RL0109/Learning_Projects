/*
    Project 5-3
    Create version of strlen
*/
#include <iostream>
#include <cstring>

int mystrlen(char* s) {

    int count = 0;

    for (int i = 0; s[i] != 0; i++) {
        ++count;
    }

    return count;

}

int main() {

    char str[80] = "Let's check the string length!";
    std::cout << "Length of string: " << mystrlen(str);

    return 0;
}