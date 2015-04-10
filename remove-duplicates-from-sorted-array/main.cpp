#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        int prev = 0;
        int current = 1;
        while(current<n){
            if(A[prev]!=A[current] && (++prev)!=current){
                A[prev] = A[current];
            }
            ++current;
        }
        return prev+1;
    }
};


int main(int argc, char** argv) {

    int A[] = {1,1,1,2,2,3};
    int count = sizeof(A)/sizeof(int);
    Solution s;

    copy(A, A+count, ostream_iterator<int>(cout, ", "));
    cout << endl;
    int result = s.removeDuplicates(A, count);
    cout << result << endl;
    copy(A, A+result, ostream_iterator<int>(cout, ", "));
    cout << endl;


    return 0;
}
