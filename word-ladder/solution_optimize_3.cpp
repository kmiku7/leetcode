#include <deque>
#include <string>
#include <list>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        deque<string> pop_from;
        deque<string> push_to;
        int total_dist = 1;
        // init
        pop_from.push_back(start);

        while(!pop_from.empty()) {
            while (!pop_from.empty()) {
                string& orig = pop_from.front();
                string node = pop_from.front();
                int dist = 0;
                for (int i = 0; i < node.length() && dist < 2; i++) {
                    if (node[i] != end[i]) {
                        ++dist;
                    }
                }
                if (dist <= 1) {
                    return total_dist + dist;
                }
                for (int i = 0; i < orig.length(); ++i) {
                    node = orig;
                    for (char j = 'a'; j <= 'z'; ++j) {
                        node[i] = j;
                        if (dict.count(node) > 0) {
                            push_to.push_back(node);
                            dict.erase(node);
                        }
                    }
                }
                pop_from.pop_front();
            }
            pop_from.swap(push_to);
            ++total_dist;
        }
        return 0;
    }
};
