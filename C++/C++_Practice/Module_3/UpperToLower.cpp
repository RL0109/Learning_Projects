/* 
    Takes chars and upper or lowercases them, counts the total times this occurs
*/


#include <iostream>
#include <vector>

using std::cout; using std::cin;

int main() {
    int upperToLowerCount = 0;
    int lowerToUpperCount = 0;

    char choice;
    for (;;) {
        do {
            cout << "Type in an ASCII character(Press . to exit): ";

            cin >> choice;
            
            if (choice == '.') {
                continue;
            }
            if (choice > 64 && choice < 91) {
                cout << "Character is an uppercase letter\n";
                choice += 32;
                cout << "converted to lowercase: " << choice << "\n";
                upperToLowerCount++;
                
            } else if(choice > 96 && choice < 128) {
                cout << "Character is a lowercase letter\n";
                choice -= 32;
                cout << "Converted to uppercase: " << choice << "\n";
                lowerToUpperCount++;
            } else {
                cout << "Character is not a letter\n";
            }

        }  while (choice != '.');

        if (choice == '.') {
            cout << "Exit key pressed ending program\n\n";
            cout << "Letters converted to uppercase: " << lowerToUpperCount << "\n";
            cout << "Letters converted to lowercase: " << upperToLowerCount << "\n";
            break;
        }
    }
}