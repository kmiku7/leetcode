#include <iostream>
#include <climits>

using namespace std;


class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n>=5) {
            n = n / 5;
            count += n;
        }
        return count;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.trailingZeroes(2147483647) << endl;
    cout << s.trailingZeroes(7) << endl;
    cout << s.trailingZeroes(10) << endl;
    cout << s.trailingZeroes(100) << endl;
    cout << INT_MAX/5 << endl;
    return 0;
}
