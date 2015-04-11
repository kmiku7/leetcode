#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string mid_result(n*2, ' ');
        // (n-left_count)*2-right_count;
        generate(result, n, 0, mid_result, 0);
        return result; 
    }

    void generate(vector<string>& result, int left_count, int right_count, string& mid_cand, int str_pos) {
        if(left_count>0){
            mid_cand[str_pos] = '(';
            generate(result, left_count-1, right_count+1, mid_cand, str_pos+1);
        }

        if(right_count>0){
            mid_cand[str_pos] = ')';
            generate(result, left_count, right_count-1, mid_cand, str_pos+1);
        }
    
        if(left_count==0 && right_count==0)
            result.push_back(mid_cand);
    }
};


int main(int argc, char** argv){

    int count = 10;
    Solution s;
    vector<string> result = s.generateParenthesis(count);
    cout << count << endl;
    cout << result.size() << endl;;
    copy(result.begin(), result.end(), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
