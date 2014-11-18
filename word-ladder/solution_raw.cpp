#include <deque>
#include <string>
#include <list>

using namespace std;

struct Record {
    string word;
    int level;
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        list<string> remain;
        deque<Record> queue;
        // init
        queue.push_back({start, 1});
        for (unordered_set<string>::iterator iter = dict.begin();
                iter != dict.end();
                iter++) {
            remain.push_back(*iter);
        }   

        while (!queue.empty()) {
            list<string> tmp;
            Record record = queue.front();
            queue.pop_front();
            int dist = distance(record.word, end);
            if (dist <= 1) {
                return record.level + dist;
            }   
    
            while (!remain.empty()) {
                string cand = remain.front();
                remain.pop_front();
                dist = distance(record.word, cand);
                if (dist <= 1) {
                    queue.push_back({cand, record.level + dist});
                } else {
                    tmp.push_back(cand);
                }   
            }   
            remain.swap(tmp);
        }   
        return 0;
    }   

private:
    int distance(string left, string right) {
        int dist = 0;
        for (int i = 0; i < left.length(); i++) {
            if (left[i] != right[i]) {
                ++dist;
            }
        }
        return dist;
    }
};
