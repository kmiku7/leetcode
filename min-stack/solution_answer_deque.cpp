#include <cstddef>
#include <deque>
#include <iostream>

using namespace std;

class MinStack {
    deque<int> stack;
    deque<int> min;

public:
    MinStack() {
    }

    void push(int x) {
        stack.push_back(x);
        if (min.size() <= 0 || x <= min.back()) {
            min.push_back(x);
        }
    }

    void pop() {
        int stack_last = stack.back();
        stack.pop_back();
        int min_last = min.back();
        if (stack_last == min_last) {
            min.pop_back();
        }
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min.back();
    }

};



