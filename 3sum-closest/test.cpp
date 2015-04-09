#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "solution.h"

using namespace std;

int main(int argc, char** argv) {

    vector<int> cases = {-1, 2, 1, -4};
    int target = 1;
    int answer = 2;

    // build
    srandom(time(NULL));
    for(int i=0; i<1000; ++i) {
        cases.push_back(random()%INT_MAX);
    }

    Solution s;

    int result = s.threeSumClosest(cases, target);

    cout << "result: " << result << endl;
    cout << "answer: " << answer << endl;

    return 0;
}
