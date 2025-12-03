/* 
    Checks the users inputs and reports the amount of periods typed
*/

#include <iostream>
#include <vector>

int main() {

    char choice;
    int periodCount = 0;
    for (;;) {
        do {

            std::cout << "Press any key!\n";

            std::cin >> choice;
            if (choice == '.') {
                ++periodCount;
            }
            std::cout << choice << " was pressed!\n";

        } while (choice != '$');

        if (choice == '$') {
            std::cout << "Period was pressed " << periodCount <<" times\n";
            break;
        }

    }


    return 0;
}
