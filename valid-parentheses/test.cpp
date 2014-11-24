#include <iostream>
#include <string>

using namespace std;

#include "solution.cpp"

string case_a[] = {"()", "()[]{}", "(]", "([)]"};

int main(int argc, char** argv) {
    Solution ss;

    for (int i = 0; i < sizeof(case_a)/sizeof(string); ++i) {
        cout << case_a[i] << " " << ss.isValid(case_a[i]) << endl;
    }


    return 0;
}
