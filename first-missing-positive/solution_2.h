#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i=0; i<n; ) {
            if( A[i]!=i+1 && 
                A[i]>0 && A[i]<=n &&
                A[A[i]-1] != A[i]   // attention! 
            ) {
                int temp = A[i];
                A[i] = A[temp-1];
                A[temp-1] = temp;
            } else {
                ++i;
            }
        }
        for(int i=0; i<n; ++i) {
            if(A[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};
