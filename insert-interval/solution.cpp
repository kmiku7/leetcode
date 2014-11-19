/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    typedef vector<Interval> InterList;
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        InterList result(intervals.size() + 1);
        int begin = newInterval.start;
        int end = newInterval.end;
        int insert_pos = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            int next_begin = intervals[i].start;
            int next_end = intervals[i].end;
            if (end < next_begin) {
                result[insert_pos] = {begin, end};
                begin = next_begin;
                end = next_end;
                ++insert_pos;
            } else if (next_end < begin) {
                result[insert_pos] = {next_begin, next_end};
                ++insert_pos;
            } else {
                begin = ((begin < next_begin) ? begin : next_begin);
                end = ((end < next_end) ? next_end : end);
            }
        }
        result[insert_pos] = {begin, end};
        ++insert_pos;
        result.resize(insert_pos);
        return result;
    }
};
