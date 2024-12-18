#include "stack.h"

Stack::Stack() : head(nullptr) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

bool Stack::isEmpty() const {
    return head == nullptr;
}

void Stack::push(StackValue value) {
    StackNode* newNode = new StackNode{value, head};
    head = newNode;
}

StackValue Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    StackNode* temp = head;
    StackValue value = temp->value;
    head = head->next;
    delete temp;
    return value;
}
