#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<int>> hash_count;

        for(int i=0; i<strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            hash_count[s].push_back(i);
        }

        vector<string> result;
        for(auto iter = hash_count.begin(); iter!=hash_count.end(); ++iter) {
            if(iter->second.size()<=1) continue;
            for(auto idx : iter->second) {
                result.push_back(strs[idx]);
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {

    vector<string> strs = {"eat", "ate", "tea", "apple", "and", "nad"};

    Solution s;

    auto result = s.anagrams(strs);
    for(auto item : result) {
        cout << item << endl;
    }

    return 0;
}
