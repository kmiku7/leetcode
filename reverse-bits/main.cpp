#include <iostream>
#include <cstdint>

using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int count = 32;
        while((count--)>0){
            result <<= 1;
            result = result | (n&0x1);
            n >>= 1;
        }
        return result;
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
