#include <algorithm>
#include <vector>
#include <iostream>
#include <time.h>
#include <climits>
#include <cstdlib>

using namespace std;


class Solution_a {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        int buffer_len = (target/candidates[0]) + 1;
        int buffer[buffer_len];
        sort(candidates.begin(), candidates.end());
        fill_next_number(candidates, 0, target, result, buffer, 0);
        return result;
    }

    void fill_next_number(vector<int>& candidates, int next_idx, int target, 
                vector<vector<int>>& result, int buffer[], int buffer_len) {
        //if(next_idx>=candidates.size() || target<=0) return;
        if(next_idx>=candidates.size()) return;

        int number = candidates[next_idx];
        int lb = 0;
        int ub = target / number;
        int curr_num_sum = ub * number;
        for(int i=0; i<ub; ++i) {
            buffer[buffer_len+i] = number;
        }
        for(; ub>=lb; --ub, curr_num_sum-=number) {
            int next_target = target - curr_num_sum;
            // assert(next_target>=0);
            if(next_target==0) result.push_back(vector<int>(buffer, buffer+buffer_len+ub));
            else fill_next_number(candidates, next_idx+1, next_target, result, buffer, buffer_len+ub);
        }
    }
};

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        for(int i=0; i<candidates.size(); ++i) {
            fill_combination(candidates, i, target, 0, combination, result);
        }
        return result;
    }
    void fill_combination(vector<int>& candidates, int next_usable_idx, int target, int sum,
                    vector<int> combination, vector<vector<int>>& result) {

        if(next_usable_idx >=candidates.size()) return;

        int next_sum = sum + candidates[next_usable_idx];
        combination.push_back(candidates[next_usable_idx]);
        if(next_sum == target) {
            result.push_back(combination);
        } else if(next_sum<target) {
            for(int i=next_usable_idx; i<candidates.size(); ++i) {
                fill_combination(candidates, i, target, next_sum, combination, result);
            }
        }
        combination.pop_back();
    }
};


int main(int argc, char** argv) {

    vector<int> nums = {2,3,5,7};
    int target = 7;

    vector<int> nums_a;
    int target_a = 0;
    {
        srandom(time(NULL));
        for(int i=0; i<30; i++) {
            nums_a.push_back(i+1);
            target_a = max(target, nums_a.back());
        }
    }   


    Solution s;
    auto result = s.combinationSum(nums_a, target_a);
    cout << nums.size() << endl;
    cout << result.size() << endl;
    for(auto line : result) {
        cout << "-----" << endl;
        cout << line.size() << ": ";
        for(auto item : line) {
            cout << item << ", ";
        }
        cout << endl;
    }
    return 0;
}
