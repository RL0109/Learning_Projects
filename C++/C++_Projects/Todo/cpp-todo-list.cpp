// cpp-todo-list2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>

unsigned int counter();


class TodoItem {
    unsigned int id;
    std::string description;
    bool completed;
    

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        id = counter();
        description = new_description;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }

    void setCompleted(bool val) { completed = val; }
};

unsigned int counter()
{
    static int count = 0;
    count++;
    return count;
}


int main()
{
    char input_option;
    int input_id;
    std::string input_description;
    std::string version = "v0.2";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    todoItems.clear();

    while(true) {
        system("cls");
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << "\n\n";
        
        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            std::string completed = it->isCompleted() ? "done" : "not done";

            std::cout << it-> getId() << " | " << it->getDescription() << " | " << completed << "\n";
        }

        if (todoItems.empty()) {
            std::cout << " Add your first todo!" << std::endl;
        }

        std::cout << "\n\n";

        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete a Todo" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "choice: ";

        std::cin >> input_option;

        switch (input_option) {
            case 'q':
                std::cout << "Have a great day now!" << std::endl;
                return 0;
            case 'c': {
                std::cout << "Enter id to mark completed: ";
                std::cin >> input_id;
                for (it = todoItems.begin(); it != todoItems.end(); it++) {

                    if (input_id == it->getId()) {
                        it->setCompleted(true);
                        break;
                    }

                }
                break;
            }
            case 'a': {
                std::cout << "Add a new description: ";
                std::cin.clear();
                std::cin.ignore();
                std::getline(std::cin, input_description);
                TodoItem newItem;
                newItem.create(input_description);
                todoItems.push_back(newItem);
                break;
            }
            default:
                std::cout << "Invalid character!";
                break;

        }

        
    }
     

    return 0;
    
}

