#include <climits>
#include <iostream>

#include "solution_1.h"

using namespace std;


int main(int argc, char** argv){

    Solution s;

    int cases[] = {
            INT_MAX, INT_MIN, 0, 
            1234567, -1234567, INT_MIN+2, 
            100, 2147443412};

    int cases_len = sizeof(cases)/sizeof(int);

    for(int i=0; i<cases_len; ++i) {
        cout<<cases[i]<<endl;
        cout<<s.reverse(cases[i])<<endl;
        cout<<endl;
    }

    return 0;
}
