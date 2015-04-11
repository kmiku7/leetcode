#include <string>
#include <vector>

using namespace std;


int base[10] = {
    0,          // 1
    'a',        // 2
    'd',        // 3
    'g',        // 4
    'j',        // 5
    'm',        // 6
    'p',        // 7
    't',        // 8
    'w',        // 9
    'z'+1,      //
};

int ccount[10] = {
    0,          // 1
    3,          // 2
    3,          // 3
    3,          // 4
    3,
    3,
    4,          // 7
    3,          // 8
    4,          // 9
};
    

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string digits_striped;
        vector<string> result;
        string cand_base;
        int total_cands = 1;
        for(auto iter=digits.begin(); iter!=digits.end(); ++iter){
            char digit = *iter;
            if(digit>='2' && digit<='9') {
                digits_striped.push_back(digit);
                cand_base.push_back(base[digit-'1']);
                total_cands *= ccount[digit-'1'];
            }
        }
        const int ds_len = digits_striped.size();
        if(ds_len<=0) return result;

        result.resize(total_cands, cand_base);
        for(int idx=0; idx<total_cands; ++idx){
            string& cand = result[idx];
            int tmp_idx = idx;
            for(int i=0; tmp_idx && i<ds_len; ++i){
                char digit = digits_striped[i]-'1';
                cand[i] = base[digit] + tmp_idx % ccount[digit];
                tmp_idx /= ccount[digit];
            }
        }
        return result;
    }
};


