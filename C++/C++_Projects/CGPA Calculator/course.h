#ifndef Course_H
#define Course_H

#include <string>
#include <iostream>
#include <vector>
class Course {
    public:
    ~Course() = default;
    Course(){}
    Course(const std::string& subject, const float& credits, const char& grade) { 
        _subject = subject;
        _credits = credits; 
        _grade = (char)toupper(grade); }

    std::string getSubject() {return _subject; }
    float getCredits() {return _credits; }
    char getGrade() {return _grade; }

    float getGradeScore () {
        switch (_grade) {
            case 'A':
                return 4.0;
            case 'B':
                return 3.0;
            case 'C':
                return 2.0;
            case 'D':
                return 1.0;
            case 'F':
                return 0.0;
            default:
                std::cout << "Invalid grade entered for " << _subject << "! " << _subject << " grade set to F\n";
                return 0.0;
        }
        

    }

    private:
        std::string _subject;
        float _credits;
        char _grade;


};



#endif

















//#endif