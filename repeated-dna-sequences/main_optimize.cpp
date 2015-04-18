#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstring>

using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.size()<=10) return result;
        int appeared_count[0x1<<20] = {0};
        char buffer[11] = {0};
        //unordered_map<int, int> appeared_count;
        const char* begin = s.c_str();
        int hash_value = 0;
        int mask = 0xFFFFF;
        for(int i=0; i<9; ++i) {
            hash_value = (hash_value<<2) | (((*begin)>>1)&0x3);
            ++begin;
        }
        while(*begin) {
            unsigned m = ((*begin)>>1)&0x3;
            hash_value = ((hash_value<<2) | m) & mask;
            ++begin;
            appeared_count[hash_value] += 1;
            if(appeared_count[hash_value]==2) {
                memcpy(buffer, begin-10, 10);
                result.push_back(buffer);
            }

        }
        return result;
               
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
