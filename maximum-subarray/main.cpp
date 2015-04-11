#include <iostream>
#include <algorithm>
#include <iterator>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int current_sum = 0;
        int max_sum = INT_MIN;
        for(int i=0; i<n; ++i) {
            current_sum += A[i];
            if(current_sum>max_sum) max_sum=current_sum;
            if(current_sum<0) current_sum=0;

        }
        return max_sum;
    }
};

int main(int argc, char** argv){

    int c[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int count = sizeof(c)/sizeof(int);

    Solution s;
    cout << s.maxSubArray(c, count) << endl;

    return 0;


}
