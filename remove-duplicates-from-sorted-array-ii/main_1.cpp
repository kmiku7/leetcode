#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<3) return n;
        int prev = 0;
        int current = 1;
        int count = 1;
        while(current<n){
            // error
            // if((A[current-1]!=A[current] || A[current-2]!=A[current])){
            if(A[current-1]==A[current]){
                if(count<2){
                    A[++prev] = A[current];
                }
                count++;
            } else {
                A[++prev] = A[current];
                count = 1;
            }
            ++current;
        }
        return prev+1;
    }
};


int main(int argc, char** argv) {

    int A[] = {1,1,1,2,2,3};
    //int A[] = {1,2,2,3};
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
