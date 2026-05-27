#include <iostream>
#include <thread>
#include <memory>

template <typename T> class LinkedListDeque {

    private:
    class ListNode {
        public:
            T item;
            ListNode *prev;
            ListNode *next;


            ListNode (T i, ListNode n, ListNode p) {
                item = i;
                next = n;
                prev = p;
            }

    };

    int size;
    std::auto_ptr<ListNode> sentinel;
    
    public:
        LinkedListDeque() {
            sentinel = ListNode(NULL, NULL, NULL);
            sentinel->next = sentinel;
            sentinel->prev = sentinel;
            size = 0;
        }

        void addFirst(T x) {
            if (size == 0) {
                std::auto_ptr<List_Node> first = new ListNode(x, sentinel, sentinel);
                sentinel -> next = first;
                sentinel -> prev = first;
                size += 1; 
            } else {

                ListNode* oldFirst = sentinel->next;
                std::auto_ptr<List_Node> first = new ListNode(x, oldFirst, sentinel);
                oldFirst->prev = first;
                sentinel->next = first;
                size +=1;

            }
        }



};




int main() 
{

    LinkedListDeque<int> test;
    test.addFirst(7);
     



}