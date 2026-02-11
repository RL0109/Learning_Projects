#ifndef Student_H
#define Student_H

#include "course.h"



class Student : public Course { 
    public: 
        std::vector<Course> Courses;
        Student() {}
        Student (const std::vector<Course>& Subjects) {
            for (auto s : Subjects) {
                Courses.push_back(s);
            }

        }

        void getAllGrades() {
            for (auto c : Courses) {
                std::cout << c.getGrade() << "\n";
            }
        }
        void getAllCredits() {
            for (auto c : Courses) {
                std::cout << c.getCredits() << "\n";
            }
        }
        void getAllSubjects() {
            for (auto c : Courses) {
                std::cout << c.getSubject() << "\n";
            }
        }


        float calculateGPA() 
        {
            for (auto c : Courses) {
                totalCredits += c.getCredits();
                scoredCredits += c.getGradeScore() * c.getCredits();
            }
            
            return scoredCredits / totalCredits;
        }

        void printTotalCredits() 
        {
            std::cout << "Total Credits: " << totalCredits << "\n";
        }

        void printScore()
        {
            
            std::cout << "Grade Points: " << scoredCredits << "\n";
        }

    private:
        float scoredCredits = 0;
        float totalCredits = 0;


};





#endif