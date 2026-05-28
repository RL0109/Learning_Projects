#include <iostream>
#include <thread>
#include <memory>
#include <list>

template <typename T> class LinkedListDeque {

    private:
    class ListNode {
        public:
            T item;
            ListNode* prev;
            ListNode* next;


            ListNode (T i, ListNode* n, ListNode* p) {
                item = i;
                next = n;
                prev = p;
            }

            ListNode() :prev(nullptr), next(nullptr) {}

    };

    int size;
    ListNode sentinel;
    
    public:
        LinkedListDeque() {
            sentinel.next = &sentinel;
            sentinel.prev = &sentinel;
            size = 0;
        }

        ~LinkedListDeque() {
            ListNode* current = sentinel.next;

            while(current != &sentinel) {
                ListNode* next = current->next;
                delete current;
                current = next;
            }
            std::cout << "Decontructed Succesfully!" << "\n";

        }

        void addFirst(T x) {
            if (size == 0) {
                ListNode* first= new ListNode(x, &sentinel, &sentinel);
                sentinel.next = first;
                sentinel.prev = first;
                size += 1; 
            } else {

                ListNode* oldFirst = sentinel.next;
                ListNode* first = new ListNode(x, oldFirst, &sentinel);
                oldFirst->prev = first;
                sentinel.next = first;
                size +=1;

            }
        }

        void addLast(T x) {
            if (size == 0) {
                ListNode* last = new ListNode(x, &sentinel, &sentinel);
                sentinel.next = last;
                sentinel.prev = last;
                size += 1;
            } else {
                ListNode* oldLast = sentinel.prev;
                ListNode* last = new ListNode(x, &sentinel, &sentinel);
                sentinel.prev->next = last;
                sentinel.prev = last;
                
                last->prev = oldLast;
                oldLast->next = last;
                size += 1;
            }
            
        }

        std::list<T> toList() {
            std::list<T> linkedList;

            ListNode* p = sentinel.next;

            while(p != &sentinel) {
                linkedList.push_back(p->item);
                p = p->next;
            }

            return linkedList;

        }

        std::list<T> backwardsList() {
            std::list<T> linkedList;

            ListNode* p = sentinel.prev;

            while(p != &sentinel) {

                linkedList.push_back(p->item);
                p = p->prev;
            }

            return linkedList;
        }

        bool isEmpty() {
            if (sentinel.next == &sentinel && sentinel.prev == &sentinel) {
                return true;
            }
            return false;
        }

        int Size () {return size;}


        T removeLast() {
            if (isEmpty() == true) {
                return NULL;
            }

            ListNode* temp = sentinel.prev;
            sentinel.prev = sentinel.prev->prev;
            sentinel.prev->next = &sentinel;
            size--;
            return temp->item;
        }

        T removeFirst() {
            if (isEmpty() == true) {
                return NULL;
            }

            ListNode* temp = sentinel.next;
            sentinel.next = sentinel.next->next;
            sentinel.next->prev = &sentinel; 
            size--;
            return temp->item;
        }

        T get(int index) {
            if (index >= size) {
                return NULL;
            }

            ListNode* p = sentinel.next;

            while (index != 0) {
                p = p->next;
                --index;
            }
            return p->item;
        }

};




int main() 
{

    LinkedListDeque<int> test;

    test.addFirst(7);
    test.addLast(14);
    test.addFirst(14);
    test.addLast(8);
    test.addFirst(0);

    std::cout << test.get(2) << "\n";

}