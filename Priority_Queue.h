#include <iostream>
#include <string>
#include <exception>
using namespace std;
class Priority_Queue
{
private:
    struct Element 
    {
        int data;
        short priority;
        struct Element* prev;
    };

    Element* back = NULL;
    Element* front = NULL;

public:
    Priority_Queue() {};
    Priority_Queue(Priority_Queue& q);
    Priority_Queue& operator=(Priority_Queue& q);
    void count_priority();
    void count_all();
    bool empty();
    void get_front();
    void pop();
    void add(int, int);
    void push();
    void print();    



};

