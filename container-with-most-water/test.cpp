#include <iostream>
#include <vector>
#include "solution_1.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {

    //vector<int> cases = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> cases = {7,6,5,4,3,2,1,0};
    int max = -1;

    srandom(time(NULL));
    for(int i=0; i<10000; ++i) {
        //cases.push_back(random()%10000);
    }


    Solution s;
    int result = s.maxArea(cases);
    cout << max << " " << result << endl;

    return 0;
}
