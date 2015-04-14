#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        if (S.empty() || T.empty())
        {
            return "";
        }
        int count = T.size();
        int require[128] = {0};
        bool chSet[128] = {false};
        for (int i = 0; i < count; ++i)
        {
            require[T[i]]++;
            chSet[T[i]] = true;
        }
        int i = -1;
        int j = 0;
        int minLen = INT_MAX;
        int minIdx = 0;
        while (i < (int)S.size() && j < (int)S.size())
        {
            if (count)
            {
                i++;
                require[S[i]]--;
                if (chSet[S[i]] && require[S[i]] >= 0)
                {
                    count--;
                }
            }
            else
            {
                if (minLen > i - j + 1)
                {
                    minLen = i - j + 1;
                    minIdx = j;
                }
                require[S[j]]++;
                if (chSet[S[j]] && require[S[j]] > 0)
                {
                    count++;
                }
                j++;
            }
        }
        if (minLen == INT_MAX)
        {
            return "";
        }
        return S.substr(minIdx, minLen);
    }
};


int main(int argc, char** argv) {
    string S = "ADOBECODEBANC";
    string T = "ABC";

    string SA = "AAAAAAAAAAABB";
    string TA = "AAAAB";

    string SB = "abc";
    string TB = "b";

    Solution s;

    cout << s.minWindow(S, T) << endl;
    cout << s.minWindow(SA, TA) << endl;
    cout << s.minWindow(SB, TB) << endl;

    return 0;
}
