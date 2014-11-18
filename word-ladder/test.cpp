#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

#include "solution.cpp"
#include "case.cpp"

int main(int argc, char** argv) {

    Solution ss;

    int dist = ss.ladderLength(case_start, case_end, paths);

    cout << "length: " << dist << endl;


    return 0;
}
