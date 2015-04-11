#include <string>
#include <vector>

using namespace std;


int cmap[10]= {
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
    

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> tmp_container;

        string::iterator begin = digits.begin();
        while(*begin=='1' && begin!=digits.end())++begin;
        if(begin!=digits.end()) result.push_back("");
        for(; begin!=digits.end(); ++begin){
            char digit = *begin;
            if(digit<'2' || digit>'9') continue;
            for(auto iter=result.begin(); iter!=result.end(); ++iter){
                for(char alpha = cmap[digit-'1']; alpha<cmap[digit-'1'+1]; ++alpha){
                    tmp_container.push_back(*iter+alpha);
                }
            }
            result.swap(tmp_container);
            tmp_container.clear();
        }
        return result;
    }
};


