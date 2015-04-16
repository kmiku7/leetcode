/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool interval_cmp(const Interval& left, const Interval& right) {
    return left.start < right.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if(intervals.size()<=0) return result;

        sort(intervals.begin(), intervals.end(), interval_cmp);
        int prev_start = intervals[0].start;
        int prev_end = intervals[0].end;
        for(auto iter = intervals.begin()+1; iter != intervals.end(); ++iter) {
            if(iter->start > prev_end) {
                result.push_back(Interval(prev_start, prev_end));
                prev_start = iter->start;
                prev_end = iter->end;
            } else {
                prev_end = max(iter->end, prev_end);
            }
        }
        result.push_back(Interval(prev_start, prev_end));
        return result;
    }
};

int main(int argc, char** argv) {

    return 0;
}
