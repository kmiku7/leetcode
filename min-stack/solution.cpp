// Time Limit Exceeded
// memory leak

#include <cstddef>


struct Item {
    int value;
    Item* stack_prev;
    Item* to_larger;
};

class MinStack {
    Item *stack_tail;
    Item *min_tail;
public:
    MinStack() {
        stack_tail = NULL;
        min_tail = NULL;
    }
    void push(int x) {
        Item* item = new Item();
        item->value = x;
        item->stack_prev = stack_tail;
        stack_tail = item;
        Item** current = &min_tail;
        while (*current != NULL && (*current)->value < x) {
            current = &((*current)->to_larger);
        }
        item->to_larger = *current;
        *current = item;
    }

    void pop() {
        if (stack_tail == NULL) {
            return;
        }
        Item* top_item = stack_tail;
        stack_tail = top_item->stack_prev;
        top_item->stack_prev = NULL;
        Item** current = &min_tail;
        while (*current != top_item) {
            current = &((*current)->to_larger);
        }
        *current = top_item->to_larger;
        top_item->to_larger = NULL;
    }

    int top() {
        if (stack_tail == NULL) {
            return -1;
        }
        return stack_tail->value;
    }

    int getMin() {
        if (min_tail == NULL) {
            return -1;
        }
        return min_tail->value;
    }
};



