//Time Limit Exceeded
//
//        "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba",
//        "a*******b",
//        "false",
#include <list>
#include <deque>
#include <cstddef>

bool isMatch(const char *s, const char *p) {
    if(*s==NULL && *p==NULL) {
        return true;
    }

    if(*s!=NULL) {
        if(*p==NULL) {
            return false;
        }
        if(*p=='?' || *p==*s) {
            return isMatch(s+1, p+1);
        }
        if(*p=='*') {
            return isMatch(s, p+1) || isMatch(s+1, p);
        }
        return false;
    }

    if(*p=='*') {
        return isMatch(s, p+1);
    }
    return false;
}

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        return ::isMatch(s, p);
    }
};
