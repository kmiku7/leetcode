#include <iostream>
#include <cstddef>
#include <cstdint>

using namespace std;


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            ++count;
            n=(n-1)&n;
        }
        return count;
    }
};

int main(int argc, char** argv) {

    uint32_t cases = 0x0F0F0;
    Solution s;

    cout << cases << endl;
    cout << hex << cases << endl;
    cout << s.hammingWeight(cases) << endl;

    return 0;
}
