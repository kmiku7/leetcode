#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
        if(num.size()==0) return result;

        vector<int> next_permutation = num;
        sort(next_permutation.begin(), next_permutation.end());
        result.push_back(next_permutation);
        if(num.size()==1) return result;

        while(true) {
            auto second = next_permutation.rbegin();
            auto first = second + 1;
            while(first!=next_permutation.rend()) {
                if(*first<*second) break;
                ++first;
                ++second;
            }
            if(first==next_permutation.rend()) break;
            auto next_cand = next_permutation.rbegin();
            while(*next_cand <= *first) ++next_cand;
            // 注意swap iterator的情况!
            // swap(first, next_cand);
            swap(*first, *next_cand);
            reverse(next_permutation.rbegin(), first);
            result.push_back(next_permutation);
        }
        return result;
    }
};


int main(int argc, char** argv) {

    vector<int> num = {9,8,8,6};
    Solution s;
    auto result = s.permute(num);
    for(auto one : result) {
        copy(one.begin(), one.end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    return 0;
}
