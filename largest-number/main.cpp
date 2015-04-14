#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;


/*
// http://stackoverflow.com/questions/979759/operator-and-strict-weak-ordering/981299#981299
bool cmp_num_str(const string& left, const string& right) {
    cout << "-----" << &left << endl;
    cout << "-----" << &right << endl;
    const char* left_c = left.c_str();
    const char* right_c = right.c_str();
    while(*left_c!='\0' && *left_c==*right_c){
        ++left_c;
        ++right_c;
    }
    cout << "end" << endl;
    //return left < right;
    if(*left_c && *right_c) return *left_c > *right_c;
    if(*left_c) return *left_c > right[0];
    // add this line, so dont core again.
    if(*right_c) return left[0] > *right_c;
    return false;
}
*/

/*
bool cmp_num_str(const string& left, const string& right) {
    int ub = min(left.size(), right.size());
    for(int i=0; i<ub; ++i) {
        if(left[i]!=right[i]) return left[i]>right[i];
    }
    if(right.size() > ub) return left[0] >= right.back();
    else if(left.size() > ub) return left.back() >= right[0];
    return left.back() > right.back();
}
*/

bool cmp_num_str(const string& left, const string& right) {
    return left+right > right+left;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        if(num.size()<=0) return "";
        vector<string> str_num;
        str_num.reserve(num.size());
        int max_value = 0;
        for(auto val : num) {
            str_num.push_back(to_string(val));
            max_value = max(max_value, val);
        }
        if(max_value <=0) return "0";
        sort(str_num.begin(), str_num.end(), cmp_num_str);
        ostringstream oss;
        for(auto& val : str_num) {
            oss << val;
        }
        return oss.str();       
    }
};


int main(int argc, char** argv) {
    //vector<int> num = {3, 30, 34, 5, 9};
    vector<int> num = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << num.size() << endl;
    Solution s;
    cout << s.largestNumber(num) << endl;

    return 0;
}
