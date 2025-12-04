/*
    Project 5-5
    Checks to see if the correct password is entered
*/
#include <iostream>
#include <cstring>

int main() {
    char password[80] = "PhillyFanatic!";
    char guess[80];
    for (;;) {
        do {
            std::cout << "Enter password:";
            std::cin >> guess;

        } while (strcmp(password, guess));
        
        if (!strcmp(password, guess)) {
            std::cout << "Correct Password!";
            break;
        }
    }


    
}