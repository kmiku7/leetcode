
#include "solution.h"

// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true


int main(int argc, char** argv) {

    char* cases[] = {
        "aa",   "a",    "false",
        "aa",   "aa",   "true",
        "aaa",  "aa",   "false",
        "aa",   "a*",   "true",
        "aa",   ".*",   "true",
        "ab",   ".*",   "true",
        "aab",  "c*a*b",    "true",
        "aaa",  "a.a",  "true",
    };

    Solution s;

    for( int i = 0; i < sizeof(cases)/sizeof(char*); i+=3) {
        bool result = s.isMatch(cases[i], cases[i+1]);
        printf("S:%s\tP:%s\tA:%s\tQ:%s\n", cases[i], cases[i+1], result?"true":"false", cases[i+2]);
    }


    return 0;
}
