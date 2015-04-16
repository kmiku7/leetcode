#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int next_mask = m + (m&-m);;
        int result = m;
        while(next_mask>m && next_mask<=n) {
            cout << next_mask << endl;
            result = result & next_mask;
            next_mask = result + (result&-result);
        }
        return result;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return m^n
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << hex << s.rangeBitwiseAnd(0x7FFF0000, 0x7FFFFFFF) << endl;
    return 0;
}
