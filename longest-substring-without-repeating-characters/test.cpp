#include <iostream>
#include "solution_2.h"

using namespace std;

int main(int argc, char** argv) {

    string  s[] = {"abcabcbb",   "bbbbb",   "aab"};
    int     q[] = {3,            1,         2};
    int     count = sizeof(q)/sizeof(int);
    Solution ser;

    for(int i = 0; i < count; ++i) {
        int result = ser.lengthOfLongestSubstring(s[i]);
        cout<<s[i]<<"\t\t"<<result<<"\t"<<q[i]<<endl;
    }

    return 0;
}
