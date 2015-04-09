#include "solution_1.h"

#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    Solution s;

    int mid = s.findMedianSortedArrays(arr1, n1, arr2, n2);

    cout << mid << endl;

    return 0;
}
