/* 
    Project that collects students grades and caluclates CGPA
*/

#include "student.h"
#include <iomanip>


int main() 
{
    std::cout << "This program takes any amount of classes and calculates a cumulative GPA.\n";
    std::cout << "Press q at anytime to end entry and begin calculation.\n";
    std::cout << "Press Ctrl + C to end program.\n\n";
    std::vector<Course> studentclasses;
    
    for (;;) {

        //Initalize variables for input stream
        std::string subject;
        std::string credit;
        std::string grade;
        std::string answer;
        //Entry loop
        do{
            std::cout << "Enter subject: ";
            std::getline(std::cin ,subject);
            if (subject == "q") 
                break;

            std::cout << "\nEnter credits for course: ";
            std::getline(std::cin , credit);
            if (credit == "q") 
                break;

            std::cout << "\nEnter grade for course: ";
            std::getline(std::cin , grade);
            if (grade == "q") 
                break;

            Course curriculum(subject, std::stof(credit), (char) grade[0]);
            studentclasses.push_back(curriculum);

        } while(true);
        std::cout << "\n\n";
        if (studentclasses.empty()) {
            std::string answer;
            std::cout << "\nEntry is empty, would you like to terminate the program? (y/n): ";
            std::getline(std::cin , answer);
            if (answer == "y") {
                std::cout << "Have a nice day!";
                return 0;
            } else if (answer == "n") {
                continue;
            } 

            continue;
        }


        // Run calculation and prints results
        Student student1(studentclasses);
        auto score = student1.calculateGPA();
        std::cout <<std::left
        << "|" <<std::setw(15) << " Course"  
        << "|" << std::setw(15) <<" Credits"
        << "|" << std::setw(15) << " Grade"<< "|\n";

        std::cout << "-------------------------------------------------------\n";

        for (auto s : studentclasses) {
            std::cout << std::left<<  "| " 
            << std::setw(14) <<  s.getSubject() << "| "
            << std::setw(14) <<  s.getCredits() << "| "
            << std::setw(14) <<  s.getGrade() << "|\n";
            std::cout << "-------------------------------------------------------\n";
        }
        student1.printScore();
        student1.printTotalCredits();
        std::cout << "Your GPA: "<<std::fixed << std::setprecision(2) << score << "\n";
        
        
        
        
        //Asks to continue
        std::cout << "\nAdd more classes? (y/n): ";
        std::getline(std::cin , answer);
        if (answer == "y") {
            continue;
        } else if (answer == "n") {
            std::cout << "\nHave a nice day!";
            return 0;
        }
 

    }




    return 0;
}
