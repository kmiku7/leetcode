#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        // assert(x>=0);
        if(x==1) return 1;

        int lb = 0;
        int ub = (x>>1)+1;
        while(lb<ub){
            int mid = lb + (ub-lb)/2;
            // 这里会溢出，需要检测。
            int pow2 = mid * mid;
            // 除法检测防止除零。
            int rem = mid ? (pow2 / mid) : mid;
            if(pow2<=x && rem==mid){
                lb = mid + 1;
            } else {
                ub = mid;
            }
        }
        return lb - 1;
    }
};


int main(int argc, char** argv) {
    int cases[] = {
        INT_MAX,
        2147395599,
        10000,
        9999,
        100,
        10,
        8,
        5,
        4,
        3,
        2,
        1,
        0,
    };
    int count = sizeof(cases)/sizeof(int);
    Solution s;

    for(int i=0; i<count; ++i){
        cout << cases[i] << " " << s.sqrt(cases[i]) << " " << sqrt(cases[i]) << endl;
    }
        

}
