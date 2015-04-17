#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>

using namespace std;


bool shift_sum(int& prev, int digit) {
    int curr = prev * 10;
    if(prev > INT_MAX/10 || curr > INT_MAX-digit) return false;
    prev = curr + digit;
    return true;
}

bool shift_neg(int& prev, int digit) {
    int curr = prev * 10;
    if(prev < INT_MIN/10 || curr < INT_MIN+digit) return false;
    prev = curr - digit;
    return true;
}

bool (*ops[2])(int&, int) = {shift_sum, shift_neg};


class Solution {
public:
    int myAtoi(string str) {

        const char* begin_pos = str.c_str();
        while(*begin_pos==' ' || *begin_pos=='\t') ++begin_pos;
        int op = 0;
        if(*begin_pos=='+' || *begin_pos=='-') {
            op = *begin_pos=='-' ? 1 : 0;
            ++begin_pos;
        }
        int result = 0;
        if(*begin_pos <'0' || *begin_pos > '9') return 0;
        while(*begin_pos >='0' && *begin_pos <='9') {
            int ret = ops[op](result, (*begin_pos)-'0');
            if(!ret) return op==0 ? INT_MAX : INT_MIN;
            ++begin_pos;
        }
        return result;
    }
};


int main(int argc, char ** argv) {

    vector<string> cases = {
        "000",
        "+000",
        "-000",
        "+1111",
        "-1234",
        "12345",
        "91234784",
        "asdf123",
        "       123",
        "    1234asdf",
        "2147483647",
        "-2147483648",
        "2147483648",
        "-2147483649",
        "214748364721474836472147483647",
    };

    Solution s;
    for(auto str : cases) {
        cout << "----------" << endl;
        cout << str << endl;
        cout << s.myAtoi(str) << endl;
        cout << atoi(str.c_str()) << endl;
    }
    return 0;
};
