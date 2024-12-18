#ifndef STACK_H
#define STACK_H

#include <stdexcept>

typedef char StackValue;

struct StackNode {
    StackValue value;
    StackNode* next;
};

class Stack {
private:
    StackNode* head;

public:
    Stack();
    ~Stack();

    bool isEmpty() const;
    void push(StackValue value);
    StackValue pop();
};

#endif // STACK_H
