#include <iostream>
#include <iterator>
#include <algorithm>

#include "solution_answer_vector.cpp"

using namespace std;

int main(int argc, char** argv) {

    MinStack stack;

    int nums[] = {8, 9, 6, 7, 4, 5, 2, 3, 0, 1};

    copy(&nums[0], &nums[sizeof(nums)/sizeof(int)], ostream_iterator<int>(cout, ", "));
    cout << endl;

    for (int i = 0; i < sizeof(nums)/sizeof(int); ++i) {
        stack.push(nums[i]);
        cout << "min:" << stack.getMin() << " tail:" << stack.top() << endl;
    }

    cout << "-----------" << endl;

    for (int i = 0; i < sizeof(nums)/sizeof(int); ++i) {
        cout << "min:" << stack.getMin() << " tail:" << stack.top() << endl;
        stack.pop();
    }

    return 0;
}
