#include <iostream>
#include "Deque.h"

int lab7_main() {
    deque *head;
    int ch;
    head = init_deque();

    std::cout << "\n Enter numbers, end with 0:" << std::endl;
    std::cin >> ch;
    while (ch != 0) {
        if (ch % 2 == 0) {
            head = push_front(ch, head);
        } else {
            head = push_back(ch, head);
        }
        std::cin >> ch;
    }

    std::cout << "Result:" << std::endl;
    int value;
    while (!is_empty(head) && peek_back(head) % 2 == 0) {
        head = pop_back(head, value);
        std::cout << value << " ";
    }
    while (!is_empty(head)) {
        head = pop_front(head, value);
        std::cout << value << " ";
    }

    std::cout << "\n Finished. Press Enter->";
    std::cin.get();
    return 0;
}
