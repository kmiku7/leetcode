#include <deque>

using namespace std;

struct Prev {
    char type;
    int count;
};

class Solution {
public:
    bool isValid(string s) {
        if (s.size() <= 0) {
            return true;
        }
        deque<char> stack;
        stack.push_back(s[0]);
        int i;
        for (i = 1; i < s.size(); ++i) {
            char cur = s[i];
            if (cur == '(' || cur == '[' || cur == '{') {
                stack.push_back(cur);
                continue;
            }
            if (stack.empty()) {
                return false;
            }
            char p = stack.back();
            if ((cur == ')' && p == '(') ||
                (cur == ']' && p == '[') ||
                (cur == '}' && p == '{')) {
                stack.pop_back();
            } else {
                return false;
            }
        }
        if (i != s.size() || !stack.empty()) {
            return false;
        }
        return true;
    }
};
