#include <iostream>
#include <cstdint>

using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int right = sizeof(uint32_t)*8 - 1;
        int left = 0;
        while(left<right){
            uint32_t lo = (n>>left)&0x1;
            uint32_t hi = (n>>right)&0x1;
            if(lo^hi){
                n = n ^ ((1U<<left) | (1U<<right));
            }
            ++left;
            --right;
        }
        return n;
    }
};


int main(int argc, char** argv) {


    uint32_t cases = 43261596;
    uint32_t expect = 964176192;

    Solution s;

    uint32_t result = s.reverseBits(cases);
    cout << hex << cases << endl;
    cout << hex << expect << endl;
    cout << hex << result << endl;
    


    return 0;
}
