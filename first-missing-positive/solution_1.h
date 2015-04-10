#include <vector>

using namespace std;


class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        vector<bool> mask(n+2, false);
        int idx = 0;
        while(idx<n){
            if(A[idx]>0 && A[idx]<=n){
                mask[A[idx]] = true;
            }
            ++idx;
        }
        idx = 1;
        while(mask[idx])++idx;
        return idx;
    }
};
