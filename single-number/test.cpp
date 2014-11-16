#include <iostream>

#include "solution.cpp"

using namespace std;

int main(int argc, char** argv) {

    Solution ss;
    int case_a[] = {1,2,3,4,5,6,7,8,9,88,77, 1,2,3,4,5,6,7,8,9,77};

    int uniq = ss.singleNumber(case_a, sizeof(case_a)/sizeof(int));
    cout << "uniq: " << uniq << endl;

    return 0;
}
