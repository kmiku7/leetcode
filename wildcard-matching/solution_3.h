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
    *np=NULL;
    return;
}

bool isMatch(char *s, char *p) {
    printf("%s\t%s\n", s, p);
    char* s_prev_star_match = s;
    char* p_prev_star_match = NULL;

    while(p && (*s || *p)) {
        printf("%p\t%c\t%p\t%c\n", s,*s, p, *p);
        if(*s==NULL && *p!='*') {
            break;
        } else if(*p==NULL) {
            p = p_prev_star_match;
            s = ++s_prev_star_match;
        } else if(*p=='?' && *s) {
            ++p;
            ++s;
        } else if(*p==*s) {
            ++p;
            ++s;
        } else if(*p=='*') {
            s_prev_star_match = s;
            p_prev_star_match = ++p;
        } else {
            p = p_prev_star_match;
            s = ++s_prev_star_match;
        }
    }
    if(s && p && *s==NULL && *p==NULL) {
        return true;
    }
    return false;
}

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        char *np = (char*)malloc(strlen(p)+1);
        compact(p, np);
        printf("C:%s\t%s\n", p, np);
        bool result = ::isMatch(const_cast<char*>(s), np);
        free(np);
        return result;
    }
};
