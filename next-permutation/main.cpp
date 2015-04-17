#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<2) return;

        auto second = num.rbegin();
        auto first = second+1;
        while(first!=num.rend()) {
            if(*first<*second) break;
            ++first;
            ++second;
        }
        if(first==num.rend()) {
            reverse(num.begin(), num.end());
            return;
        }
        auto next_cand = num.rbegin();
        while(*next_cand<=*first) ++next_cand;
        swap(*first, *next_cand);
        reverse(num.rbegin(), first);
    }
};


int main(int argc, char** argv) {

    vector<vector<int>> cases = {
        {1,2,3},
        {3,2,1},
        {1,1,5},
    };
    Solution s;
    for(auto line : cases) {
        copy(line.begin(), line.end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
        s.nextPermutation(line);
        copy(line.begin(), line.end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
