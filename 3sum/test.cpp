#include "solution_2.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <climits>

using namespace std;

int main(int argc, char** argv) {


    vector<int> cases = 
{7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};

    vector<int> cases_a = {-1, 0, 1, 2, -1, -4};
    Solution s;

    // build
    srandom(time(NULL));
    for(int i=0; i<1000; ++i) {
        //cases.push_back(random()%INT_MAX);
    }



    copy(cases.begin(), cases.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    auto result = s.threeSum(cases);

    for(auto iter = result.begin(); iter != result.end(); ++iter) {
        copy((*iter).begin(), (*iter).end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
