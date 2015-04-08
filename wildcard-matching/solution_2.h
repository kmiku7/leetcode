//Time Limit Exceeded
//
//        "abbaaaabaaabbbbaabbbbaaaabababababbababbaaabbbabbbaab",
//        "*a***b**b**ba***a****",
//        "true",
#include <list>
#include <deque>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <cstdio>

// the len of np is larger than p
void compact(const char *p, char *np){
    *np = NULL;
    if(*p==NULL) {
        return;
    }
    *np = *p;
    ++p;
    ++np;
    while(*p!=NULL) {
        if(!(*p=='*'&&(*(p-1))=='*')) {
            *np = *p;
            ++np;
        }
        ++p;
    }
    return;
}

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
        char *np = (char*)malloc(strlen(p)+1);
        compact(p, np);
        bool result = ::isMatch(s, np);
        free(np);
        return result;
    }
};
