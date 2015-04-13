#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;
#define SOLUTION Solution
class Solution {
public:
int numDistinct(string S, string T) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    int match[200];  
    if(S.size() < T.size()) return 0;  
    match[0] = 1;  
    for(int i=1; i <= T.size(); i++)  
      match[i] = 0;  
    for(int i=1; i<= S.size(); i ++) {
       for(int j =T.size(); j>=1; j--)  
         if(S[i-1] == T[j-1])  
           match[j]+= match[j-1];  
     }
     return match[T.size()];  
   }  
};


// Time Limit Exceeded
class Solution_a {
public:
    int numDistinct(string S, string T){
        return mcount(S, T, 0, 0);
    }

    int mcount(const string& S, const string& T, int si, int ti) {
        if(ti>=T.size()) {
            return 1;
        }
        if(si>=S.size()) return 0;

        int sub_count = 0;
            for(int j=si; j<S.size(); ++j) {
                if(T[ti]==S[j]) sub_count += mcount(S, T, j+1, ti+1);
            }
        return sub_count;
    }
};

class Solution_b {
public:
    int numDistinct(string S, string T) {
        if(S.size()<T.size()) return 0;
        vector<int> prev_ti(S.size()+1, 1);
        vector<int> curr_ti(S.size()+1, 0);
        int prev_si = 0;

        for(int ti=0; ti<T.size(); ++ti) {
            prev_si = 0;
            for(int si=ti; si<S.size(); ++si) {
                curr_ti[si+1] = prev_si + ((T[ti]==S[si]) ? prev_ti[si] : 0);
                prev_si = curr_ti[si+1];
            }
            curr_ti.swap(prev_ti);
        
        }
        return prev_ti[S.size()];
    }
};


int main(int argc, char** argv) {

    string S = "fff";
    string T = "fff";


    Solution s1;
    cout << s1.numDistinct(S,T) << endl;
    Solution_a s2;
    cout << s2.numDistinct(S,T) << endl;
    Solution_b s3;
    cout << s3.numDistinct(S,T) << endl;

    return 0;
}

