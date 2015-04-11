#include "solution_other.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


struct CASE{
    string input;
    int rows;
    string output;
};

int main(int argc, char** argv) {

    CASE cases[] = {
        {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
        {"ABCDEFGH", 2, "ACEGBDFH"},
        {"ABCDEFGHIJ", 3, "AEIBDFHJCG"},
        {"ABCDEFGHIJKLM", 4, "AGMBFHLCEIKDJ"},
        {"ABCDEFGHIJKLMNOPQ", 5, "AIQBHJPCGKODFLNEM"},
        {"ABC", 1, "ABC"},
    };

    int cases_count = sizeof(cases)/sizeof(CASE);

    Solution s;

    for(int i=0; i<cases_count; ++i){
        string result = s.convert(cases[i].input, cases[i].rows);
        printf("input:%s\noutput:%s\nexpect:%s\nrows:%d\n\n",
                cases[i].input.c_str(),
                result.c_str(),
                cases[i].output.c_str(),
                cases[i].rows);
    }

    return 0;
}

