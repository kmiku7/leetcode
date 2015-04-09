#include <cstdlib>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;

        int sign = x<0?-1:1;
        x = x<0?-x:x;
        int prev_result = 0;
        int result = 0;
        int result_div_10 = 0;

        while(x && result_div_10==prev_result){
            prev_result = result;
            result = result*10 + x%10;
            x = x/10;
            result_div_10 = result / 10;
        }
        return sign*result*(result_div_10==prev_result);
    }
};
