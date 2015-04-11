#include <vector>
#include <string>
#include "Solution.h"
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    vector<string> cases = {
        "23",
        "1",
        "111",
        "212",
        "123",
        string(15,'4'),
    };

    Solution s;

    for(auto iter=cases.begin(); iter!=cases.end(); ++iter) {
        vector<string> result = s.letterCombinations(*iter);
        cout << *iter << endl;
        copy(result.begin(), result.end(), ostream_iterator<string>(cout, ", "));
        cout << endl << endl;
    }


    return 0;
}
