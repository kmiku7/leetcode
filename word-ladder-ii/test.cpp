#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <cassert>

using namespace std;

#include "solution.cpp"
#include "case.cpp"

/*
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/
void print_deque(deque<string>& d) {
    copy(d.begin(), d.end(), ostream_iterator<string>(cout, ", "));
    cout << endl;
}

int main(int argc, char** argv) {

    Solution ss;

    //for (int i = 0; i < 10000; ++i) {
    //    vector<vector<string>> result = ss.findLadders(case_start, case_end, paths);
    //}
    vector<vector<string>> result = ss.findLadders(case_start, case_end, paths);
    cout << "----- output -----" << endl;
    for (vector<vector<string>>::iterator iter = result.begin();
            iter != result.end();
            ++iter) {
        copy((*iter).begin(), (*iter).end(), ostream_iterator<string>(cout, ", "));
        cout << endl;
    }

    return 0;
}
