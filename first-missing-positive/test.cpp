#include "Solution.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char** argv) {

    int c1[] = {1,2,0};
    int l1 = sizeof(c1)/sizeof(int);
    int a1 = 3;
    int c2[] = {3,4,-1,1};
    int l2 = sizeof(c2)/sizeof(int);
    int a2 = 2;
    int c3[] = {1,1};
    int l3 = sizeof(c3)/sizeof(int);
    int a3 = 2;
    Solution s;

    int q1 = s.firstMissingPositive(c1, l1);
    cout << q1 << endl;
    int q2 = s.firstMissingPositive(c2, l2);
    cout << q2 << endl;
    int q3 = s.firstMissingPositive(c3, l3);
    cout << q3 << endl;

}
