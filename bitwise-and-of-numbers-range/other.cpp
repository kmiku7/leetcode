#include <iostream>
using namespace std;


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = n^m;
        int cnt = 0;
        while(res) {
            res = res>>1;
            cnt++;
        }
        return m>>cnt<<cnt;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << hex << s.rangeBitwiseAnd(0x7FFF0000, 0x7FFFFFFF) << endl;
    cout << hex << s.rangeBitwiseAnd(5, 14) << endl;
    return 0;
}
