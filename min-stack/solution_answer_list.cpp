#include <cstddef>
#include <iostream>

using namespace std;

struct Item {
    int value;
    Item* stack_prev;
};

struct MinItem {
    int value;
    int count;
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
        if (min_tail == NULL || x < min_tail->value) {
            MinItem* min_item = new MinItem();
            min_item->value = x;
            min_item->count = 1;
            min_item->min_prev = min_tail;
            min_tail = min_item;
        } else if (x == min_tail->value) {
            min_tail->count += 1;
        }
        stack_tail = item;
    }

    void pop() {
        if (stack_tail == NULL) {
            return;
        }
        Item* top_item = stack_tail;
        stack_tail = top_item->stack_prev;
        top_item->stack_prev = NULL;
        if (top_item->value == min_tail->value) {
            min_tail->count -= 1;
            if (min_tail->count <= 0) {
                MinItem* min_item = min_tail;
                min_tail = min_item->min_prev;
                min_item->min_prev = NULL;
                delete min_item;
            }
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
        if (min_tail == NULL) {
            return -1;
        }
        return min_tail->value;
    }

};



