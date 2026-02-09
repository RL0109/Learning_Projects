// cpp-calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>



int main()
{
    // define variables
    char operation;
    double value1;
    double value2;
    double sum;
    system("cls");
    std::cout << "Press Ctrl + C to exit.\n";

    

    for (;;) {
        do {
            std::cout << "Enter 1st value: ";
            std::cin >> value1;
            std::cout << "\nEnter 2nd value: ";
            std::cin >> value2;
            std::cout << "\nInput operation: ";
            std::cin >> operation;

            switch (operation) {
                case '-':
                    std::cout << value1 << " - " << value2 << " = " << value1 - value2 << "\n\n";
                    break;
                case '+':
                    std::cout <<value1 << " + " << value2 << " = " << value1 + value2 << "\n\n";
                    break;
                case '*':
                    std::cout << value1 << " * " << value2 << " = " << value1 * value2 << "\n\n";
                    break;
                case '/':
                    std::cout << value1 << " / " << value2 << " = " << value1 / value2 << "\n\n";
                    break;
                case '^':
                    std::cout << value1 << " ^ " << value2 << " = " << std::pow(value1, value2) << "\n\n";
                    break;
                default:
                    std::cout << "Not a valid character";
            }
        } while (operation != 'q');

        if (operation == 'q') {
            break;
        }
    }
    
    return 0;
}
