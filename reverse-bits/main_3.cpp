#include <iostream>
#include <cstdint>

using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n&0x55555555)<<1 | (n&0xaaaaaaaa)>>1);
        n = ((n&0x33333333)<<2 | (n&0xcccccccc)>>2);
        n = ((n&0x0f0f0f0f)<<4 | (n&0xf0f0f0f0)>>4);
        n = ((n&0x00ff00ff)<<8 | (n&0xff00ff00)>>8);
        n = ((n&0x0000ffff)<<16 | (n&0xffff0000)>>16);
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
