#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.size()<=10) return result;
        unordered_map<int, int> appeared_count;
        for(int begin=0, sential=s.size()-10; begin<=sential; ++begin) {
            int hash_value = hash_string_10(s, begin);
            appeared_count[hash_value] += 1;
            if(appeared_count[hash_value]==2) {
                result.push_back(s.substr(begin, 10));
            }
        }
        return result;
               
    }
private:
    int hash_string_10(const string& s, int begin) {
        // assert(s.size()<=begin+10);
        int value = 0;
        for(int i=0; i<10; ++i) {
            value = (value<<2) | ((s[begin+i] >> 1) & 0x3);
        }
        return value;
    }
};


int main(int argc, char** argv) {

    Solution s;
    string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto result = s.findRepeatedDnaSequences(str);
    for(auto item : result) {
        cout << item << endl;
    }

    return 0;
}
