#include "Deque.h"

deque* init_deque() {
    return nullptr;
}

bool is_empty(deque* head) {
    return head == nullptr;
}

deque* push_front(t_elem value, deque* head) {
    deque* new_node = new deque;
    new_node->data = value;
    new_node->next = head;
    new_node->prev = nullptr;

    if (head != nullptr) {
        head->prev = new_node;
    }

    return new_node;
}

deque* push_back(t_elem value, deque* head) {
    if (head == nullptr) {
        return push_front(value, head);
    }

    deque* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    deque* new_node = new deque;
    new_node->data = value;
    new_node->next = nullptr;
    new_node->prev = temp;
    temp->next = new_node;

    return head;
}

deque* pop_front(deque* head, t_elem& value) {
    if (head == nullptr) return nullptr;

    deque* temp = head;
    value = head->data;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    return head;
}

deque* pop_back(deque* head, t_elem& value) {
    if (head == nullptr) return nullptr;

    deque* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    value = temp->data;
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    return head;
}

t_elem peek_back(deque* head) {
    if (head == nullptr) return -1;

    deque* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->data;
}