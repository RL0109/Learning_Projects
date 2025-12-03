/*
    Project 4-4
    Compares two strings but ignores case
*/
#include <iostream>
#include <cstring>

int main() {
    char str1[80];
    char str2[80];


    std::cout << "Type word 1: ";
    std::cin >> str1;
    std::cout << "Type word 2: ";
    std::cin >> str2;

    char *p1, *p2;
    p1 = str1;
    p2 = str2;

    for (int i = 0; i < strlen(str1); i++) {
        p1[i] = tolower(p1[i]);
        p2[i] = tolower(p2[i]);
    }

    if (!strcmp(str1, str2)) {
        std::cout << "Strings match";
    } else {
        std::cout << "Strings do not match\n";
    }


    return 0;
}