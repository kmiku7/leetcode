//#include "solution.h"
#include "solution_3.h"
#include <cstdio>

using namespace std;

int main(int argc, char** argv) {

/**
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

    char *cases[] = {
        "aa",   "a",    "false",
        "aa",   "aa",   "true",
        "aaa",  "aa",   "false",
        "ab",   "ab?",  "false",
        "a",    "*",    "true",
        "aa",   "*",    "true",
        "aa",   "a*",   "true",
        "ab",   "?*",   "true",
        "aab", "c?a?b", "false",

        "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba",
        "a*******b",
        "false",

        "abbaaaabaaabbbbaabbbbaaaabababababbababbaaabbbabbbaab",
        "*a***b**b**ba***a****",
        "true",

        "abcd",
        "*?*?*?*?",
        "true",

    };
    int cases_len = sizeof(cases)/sizeof(char*);

    Solution solution;

    for(int i = 0; i < cases_len; i+=3) {
        bool result = solution.isMatch(cases[i], cases[i+1]);
        printf("STR:%s\tPTN:%s\tA:%s\tQ:%s\n", cases[i], cases[i+1], result?"true":"false", cases[i+2]);
    }   

    return 0;
}
