#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()==0) return s2==s3;
        if(s2.size()==0) return s1==s3;
        if(s1.size() + s2.size() != s3.size()) return false;

        vector<bool> prev_1(s1.size(), false);
        vector<bool> curr_1(s1.size(), false);      
        vector<bool> prev_2(s2.size(), false);
        vector<bool> curr_2(s2.size(), false);

        prev_1[0] = s1[0] == s3[0];
        prev_2[0] = s2[0] == s3[0];

        for(int i=1; i<s3.size(); ++i) {
            for(int j=0, ub=min(i+1, (int)s1.size()); j<ub; ++j) {
                curr_1[j] = (s1[j] == s3[i] && 
                    (   ((j-1)>=0 && prev_1[j-1]) 
                        || ((i-j-1)>=0 && (i-j-1)<s2.size() && prev_2[i-j-1])));
            }
            for(int j=0, ub=min(i+1, (int)s2.size()); j<ub; ++j) {
                curr_2[j] = (s2[j] == s3[i] && 
                    (   ((j-1)>=0 && prev_2[j-1]) 
                        || ((i-j-1)>=0 && (i-j-1)<s1.size() && prev_1[i-j-1])));
            }
            prev_1.swap(curr_1);
            prev_2.swap(curr_2);

        }

        return prev_1[prev_1.size()-1] || prev_2[prev_2.size()-1];
    }
};


int main(int argc, char** argv) {

    string s1 = "aabcc";
    string s2 = "dbbca";

    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";

    Solution s;

    cout << s.isInterleave(s1, s2, s3) << endl; 
    cout << s.isInterleave(s1, s2, s4) << endl; 

    string a1 = "";
    string a2 = "";
    string a3 = "";

    cout << s.isInterleave(a1, a2, a3) << endl; 

    return 0;
}
