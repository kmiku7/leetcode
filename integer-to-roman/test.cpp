#include <iostream>
#include <string>

#include "solution.h"

using namespace std;

struct CASE{
    int number;
    string roman;
};

int main(int argc, char** argv) {


    CASE cases[] = {
        {1, "I"},
        {28,"XXVIII"},
        {3999, "MMMCMXCIX"}
    };
    int cases_count = sizeof(cases)/sizeof(CASE);
    Solution s;

    for(int i=0; i<cases_count; ++i){
        cout << cases[i].number << endl;
        cout << cases[i].roman << endl;
        cout << s.intToRoman(cases[i].number) << endl;
        cout << endl;
    }


    return 0;
}
