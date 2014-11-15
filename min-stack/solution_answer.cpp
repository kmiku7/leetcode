// Memory Limit Exceeded

#include <cstddef>

struct Item {
    int value;
    Item* stack_prev;
};

struct MinItem {
    Item* value;
    MinItem* min_prev;
};

class MinStack {
    Item*  stack_tail;
    MinItem* min_tail;

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

        if (min_tail == NULL || x <= min_tail->value->value) {
            MinItem* min_item = new MinItem();
            min_item->value = item;
            min_item->min_prev = min_tail;
            min_tail = min_item;
        }
    }

    void pop() {
        if (stack_tail == NULL) {
            return;
        }
        Item* top_item = stack_tail;
        stack_tail = top_item->stack_prev;
        top_item->stack_prev = NULL;
        if (min_tail->value == top_item) {
            MinItem* min_item = min_tail;
            min_tail = min_tail->min_prev;
            delete min_item;
        }
        delete top_item;
    }

    int top() {
        if (stack_tail == NULL) {
            return -1;
        }
        return stack_tail->value;
    }

    int getMin() {
        if (min_tail <= 0) {
            return -1;
        }
        return min_tail->value->value;
    }

};



