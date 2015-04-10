#include "solution.h"
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    int nums[] = {1,2,3,4,5,6,7};
    int count = sizeof(nums)/sizeof(int);
    int k = 1;

    Solution s;

    copy(nums, nums+count, ostream_iterator<int>(cout, ", "));
    cout << endl;

    s.rotate(nums, count, k);

    copy(nums, nums+count, ostream_iterator<int>(cout, ", "));
    cout << endl;


    return 0;
}
