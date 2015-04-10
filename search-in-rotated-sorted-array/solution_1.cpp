#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

// You may assume no duplicate exists in the array.

int test_case[] = {4, 5, 6, 7, 0, 1, 2};


class Solution {
public:
    int search(int A[], int n, int target) {
        int begin = 0;
        int end = n;
        int middle = 0;
        while (begin < end) {
            middle = ((end - begin) >> 1) + begin;
            if (A[middle] == target) {
                return middle;
            }
            if(A[begin] <= A[middle]){
                if(target<A[middle] && target>=A[begin]){
                    end = middle;
                } else {
                    begin = middle+1;
                }
            } else {
                if(target>A[middle] && target<=A[end-1]){
                    begin = middle+1;
                } else {
                    end = middle;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char** argv) {

    int count = sizeof(test_case) / sizeof(int);
    Solution ss;

    int idx_6 = ss.search(test_case, count, 6);
    int idx_1 = ss.search(test_case, count, 1);
    int idx_100 = ss.search(test_case, count, 100);

    copy(&test_case[0], &test_case[count], ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << idx_6 << endl;
    cout << idx_1 << endl;
    cout << idx_100 << endl;
    return 0;
}
