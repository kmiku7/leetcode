#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;


class Solution {
public:
    string preProcess(const string& s){
        int len = s.length();
        string expanded(s.length()*2+2, '#');
        expanded[0] = '^';
        for(int i=0; i<len; ++i) {
            expanded[(i<<1)+2]=s[i];
        }
        return expanded;
    }
    string longestPalindrome(string s) {
        string expanded = preProcess(s);
        int len = expanded.length();
        int *P = (int*)malloc(len*sizeof(int));
        P[0]=0;
        P[1]=0;

        int C=1;
        int R=1;

        for(int i=2; i<len; ++i){
            int i_mirror = C+C-i;
            P[i] = R>i?(P[i_mirror]>(R-i)?(R-i):P[i_mirror]):0;
            while(expanded[i-P[i]-1]==expanded[i+P[i]+1]){
                ++P[i];
            }
            if(i+P[i]>R){
                C=i;
                R=i+P[i];
            }
        }

        int max_center = 2;
        int max_len = 1;
        for(int i=3; i<len; ++i) {
            if(P[i]>max_len){
                max_center=i;
                max_len=P[i];
            }
        }
        free(P);

        return s.substr(((max_center-1)>>1)-(max_len>>1), max_len);
    }
};


