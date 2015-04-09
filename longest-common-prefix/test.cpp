#include "solution.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>

using namespace std;


int main(int argc, char** argv) {

    vector<string> cases = \
        {"123456", "123457", "123458", "123459", "123", "asdf"};

    Solution s;
 
        string result = s.longestCommonPrefix(cases);
        copy(cases.begin(), cases.end(), 
                ostream_iterator<string>(cout, "\n"));
        cout << endl << result << endl;


    return 0;
}
