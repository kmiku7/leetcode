#include <vector>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(auto &val : tokens) {
            if(val=="/") {
                int right = stack.back();
                stack.pop_back();
                stack.back() /= right;
            } else if(val=="+") {
                int right = stack.back();
                stack.pop_back();
                stack.back() += right;
            } else if(val=="*") {
                int right = stack.back();
                stack.pop_back();
                stack.back() *= right;
            } else if(val=="-") {
                int right = stack.back();
                stack.pop_back();
                stack.back() -= right;
            } else {
                stack.push_back(stoi(val));
            }
        }
        return stack.back();
    }
};



int main(int argc, char** argv) {

    vector<string> ca = {"2", "1", "+", "3", "*"};
    vector<string> cb = {"4", "13", "5", "/", "+"};

    Solution s;

    cout << s.evalRPN(ca) << endl;
    cout << s.evalRPN(cb) << endl;


    return 0;
}
