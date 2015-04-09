#include <string>
#include <iostream>

using namespace std;


int decimal_map[26] = {
    0,      // A
    0,      // B
    100,    // C
    500,    // D
    0,      // E
    0,
    0,
    0,
    1,      // I
    0,
    0,
    50,     // L
    1000,   // M
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    5,      // V
    0,      
    10,     // X
    0,
    0,
};


class Solution {
public:
    int romanToInt(string s) {
        if(s.length()<=0) return 0;

        int result = 0;
        int len = s.length();
        int prev_digit = decimal_map[s[0]-'A'];
        int current_digit = 0;
        for(int i=1; i<len; ++i) {
            current_digit = decimal_map[s[i]-'A'];
            if(current_digit>prev_digit){
                result-=prev_digit;
            }else{
                result+=prev_digit;
            }
            prev_digit=current_digit;
        }
        return result + prev_digit;
    }
};
