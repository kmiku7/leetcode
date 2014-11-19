#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

#include "solution.cpp"


void print(vector<Interval>& intervals) {
    cout << "-----------------" << endl;
    for (vector<Interval>::iterator iter = intervals.begin();
            iter != intervals.end();
            ++iter) {
        cout << iter->start << ", " << iter->end << endl;
    }
}

int main(int argc, char** argv) {

/**
Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
*/

    vector<Interval> case_a({{1,3}, {6,9}});
    Interval case_a_insert(2, 5);

    vector<Interval> case_b({{1,2}, {3,5}, {6,7}, {8,10}, {12,16}});
    Interval case_b_insert(4, 9);
    
    vector<Interval> case_c({{1,5}});
    Interval case_c_insert(6, 8);

    vector<Interval> case_d;
    Interval case_d_insert(5, 7);

    Solution ss;

    vector<Interval> case_a_result = ss.insert(case_a, case_a_insert);
    print(case_a_result);

    vector<Interval> case_b_result = ss.insert(case_b, case_b_insert);
    print(case_b_result);

    vector<Interval> case_c_result = ss.insert(case_c, case_c_insert);
    print(case_c_result);

    vector<Interval> case_d_result = ss.insert(case_d, case_d_insert);
    print(case_d_result);

    return 0;
}
