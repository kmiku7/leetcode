// Memory Limit Exceeded
//
#include <list>
#include <deque>
#include <cstddef>

struct SubMatch {
    int s_start;
    int p_start;
};

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        //std::list<SubMatch> sub_matches;
        std::deque<SubMatch> sub_matches;
        sub_matches.push_back(SubMatch{0, 0});

        while(!sub_matches.empty()) {
            int s_start = sub_matches.front().s_start;
            int p_start = sub_matches.front().p_start;
            sub_matches.pop_front();

            if(*(s+s_start) == NULL && *(p+p_start) == NULL){
                return true;
            }

            if(*(s+s_start) != NULL) {
                if(*(p+p_start) == NULL) {
                    continue;
                }

                if(*(p+p_start) == '?' || *(p+p_start) == *(s+s_start)) {
                    sub_matches.push_back(SubMatch{s_start+1, p_start+1});
                }

                if(*(p+p_start) == '*') {
                    sub_matches.push_back(SubMatch{s_start, p_start+1});
                    sub_matches.push_back(SubMatch{s_start+1, p_start});
                }

                continue;
            }

            if(*(p+p_start) == '*') {
                sub_matches.push_back(SubMatch{s_start, p_start+1});
            }
            // continue;
        }

        return false;
    }
};
