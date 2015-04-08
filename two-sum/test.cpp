#include "solution_1.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int numbers_raw[] = {3, 2, 4};
    int target = 6;
    vector<int> numbers(&numbers_raw[0], &numbers_raw[sizeof(numbers_raw)/sizeof(int)]);

    Solution s;

    vector<int> result = s.twoSum(numbers, target);

    cout << result.size() << endl;
    cout << result[0] << endl;
    cout << result[1] << endl;


    return 0;
}
