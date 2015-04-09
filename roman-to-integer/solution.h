#include <string>
#include <iostream>

using namespace std;



class Solution {
public:
    int romanToInt(string s) {
        if(s.length()<=0) return 0;

        int decimal_map['Z'] = {0};
        decimal_map['I'] = 1;
        decimal_map['V'] = 5;
        decimal_map['X'] = 10;
        decimal_map['L'] = 50;
        decimal_map['C'] = 100;
        decimal_map['D'] = 500;
        decimal_map['M'] = 1000;

        int result = 0;
        int len = s.length();
        int prev_digit = decimal_map[s[0]];
        int current_digit = 0;
        for(int i=1; i<len; ++i) {
            current_digit = decimal_map[s[i]];
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
