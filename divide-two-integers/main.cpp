#include <iostream>
#include <climits>

using namespace std;


class Solution {
public:
    int divide(int raw_dividend, int raw_divisor) {
        if((raw_dividend==INT_MIN && raw_divisor==-1) || raw_divisor==0) return INT_MAX;

        int shift_count = 0;
        int result = 0;
        int sign = (raw_dividend & 0x1<<31) ^ (raw_divisor & 0x1<<31);
        unsigned int dividend = (raw_dividend < 0) ? -raw_dividend : raw_dividend;
        unsigned int divisor = (raw_divisor < 0) ? -raw_divisor : raw_divisor;

        unsigned int tmp_divisor = divisor;
        // 这里取 first A[x] >= target 的原因是？
        // 防止溢出。
        while(tmp_divisor<dividend){
            tmp_divisor <<= 1;
            ++shift_count;
        }
        if(tmp_divisor>dividend)
            shift_count -= 1;

        unsigned int dividend_rem = dividend;
        while(shift_count>=0 && dividend_rem >= divisor){
            tmp_divisor = divisor << shift_count;
            if(dividend_rem >= tmp_divisor){
                result |= (0x1<<shift_count);
                dividend_rem -= tmp_divisor;
            }
            shift_count -= 1;
        }

        return (sign != 0) ? -result : result;
    }
}; 


int main(int argc, char** argv) {

    int cases[] = {
        INT_MAX,    INT_MAX,
        INT_MIN,    INT_MIN,
        INT_MAX,    INT_MIN,
        INT_MIN,    INT_MAX,
        100,        33,
        10,         2,
        11,         3,
    };
    int count = sizeof(cases)/sizeof(int);
    Solution s;

    for(int i=0; i<count; i+=2){
        cout << cases[i] << " " << cases[i+1] << " ";
        cout << s.divide(cases[i], cases[i+1]) << " ";
        cout << cases[i] / cases[i+1] << endl;
    }

    return 0;
}
