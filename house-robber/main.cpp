#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

#include "solution.h"

using namespace std;


int main(int argc, char** argv) {

    vector<int> cases = {6,7,1,2,4,3,5};
    copy(cases.begin(), cases.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    Solution s;
    int result = s.rob(cases);
    cout << result << endl;

    return 0;
}
