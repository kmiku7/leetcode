#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <deque>

using namespace std;


struct Frame {
    char    character;
    char    flag;
};

void expand_pattern(const char* p, Frame* np) {
    while(*p) {
        char c = *p;
        char f = '=';

        ++p;

        if(*p=='*') {
            f = '*';
            ++p;
        }

        //printf("ADDR:%p\t%c\t%c\n", np, c, f);
        *np = Frame{c, f};
        ++np;
    }
    *np = Frame{NULL, '='};
}

bool isMatch(const char *s, Frame* p) {

    deque<pair<int, int> > stack;
    int str_pos = 0;
    int pattern_pos = 0;

    while(true) {
        Frame* ptn_char = p+pattern_pos;
        //printf("INX:%d\tSTR:%d\n", pattern_pos, str_pos);
        //printf("P:%c,%c\tS:%c\n", ptn_char->flag, ptn_char->character, s[str_pos]);

        if(ptn_char->flag == '=') {
            if(ptn_char->character == s[str_pos] || 
                (ptn_char->character == '.' && s[str_pos] != NULL)) {
                if(s[str_pos] == NULL) {
                    return true;
                }
                str_pos++;
                pattern_pos++;
            } else {
                // backtrack
                bool retry = false;
                while(!stack.empty()){
                    str_pos = stack.back().first;
                    pattern_pos = stack.back().second;
                    stack.pop_back();

                    if(p[pattern_pos].character=='.') {
                        if(s[str_pos] == NULL) {
                            return false;
                        } else {
                            stack.push_back(make_pair(str_pos+1, pattern_pos));
                            pattern_pos++;
                            str_pos++;
                            retry = true;
                            break;
                        }
                    } else {
                        if(s[str_pos] == p[pattern_pos].character) {
                           stack.push_back(make_pair(str_pos+1, pattern_pos));
                            pattern_pos++;
                            str_pos++;
                            retry = true;
                            break;
                        }
                    }
                }
                if(!retry){
                    return false;
                }
            }
        } else /* if(ptn_char->flag == '*') */ {
            stack.push_back(make_pair(str_pos, pattern_pos));
            pattern_pos++;
        }
    }

    return true;
}

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        Frame* np = static_cast<Frame*>(malloc(sizeof(Frame)*(strlen(p)+1)));
        expand_pattern(p, np);
        bool result = ::isMatch(s, np);
        free(np);
        return result;
    }
};
