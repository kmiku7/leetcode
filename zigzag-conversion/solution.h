#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<=1) return s;
        int members_count = 2*nRows-2;
        int left = 0+1, right = members_count-1;
        int len = s.length();
        int ri = 0;
        string result(len, '#');

        // first line & last line;
        ri = 0;
        for(int si=0; ri<len && si<len; ++ri, si+=members_count){
            result[ri] = s[si];
        }

        // middle line;
        while(left<right){
            int si = 0;
            while(si+left<len && ri<len){
                result[ri++] = s[si+left];
                if(si+right<len){
                    result[ri++] = s[si+right];
                }
                si+=members_count;
            }
            ++left;
            --right;
        }

        // last line;
        for(int si=nRows-1; ri<len && si<len; ++ri, si+=members_count){
            result[ri] = s[si];
        }
        return result;
    }
};
