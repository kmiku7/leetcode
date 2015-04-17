#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0, ub=(int)haystack.size() - (int)needle.size();
            i<=ub;
            ++i) {
            int j=0;
            while(needle[j]==haystack[i+j] && j<needle.size()) ++j;
            if(j==needle.size()) return i;
        }
        return -1;       
    }
};


int main(int argc, char** argv) {

    string a = "123456789";
    string b = "345";
    string c = "abc";
    string d = "aaaaaaaaaaaaaaaaaaaaaaaaaa";

    Solution s;
    cout << s.strStr(a, b) << endl;
    cout << s.strStr(a, c) << endl;
    cout << s.strStr(a, d) << endl;

    return 0;
}
