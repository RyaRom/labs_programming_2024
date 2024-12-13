#ifndef DEQUE_CUH
#define DEQUE_CUH
typedef int t_elem;

struct deque {
    t_elem data;
    deque* next;
    deque* prev;
};

deque* init_deque();
bool is_empty(deque*);
deque* push_front(t_elem, deque*);
deque* push_back(t_elem, deque*);
deque* pop_front(deque*, t_elem&);
deque* pop_back(deque*, t_elem&);
t_elem peek_back(deque*);
#endif //DEQUE_CUH
