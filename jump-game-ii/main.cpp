#include <iostream>
#include <vector>
#include <climits>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> count(nums.size(), INT_MAX);

        count[0] = 0;
        for(int i=0; i<nums.size(); ++i) {
            for(int j=i+1; j<nums.size() && j<=i+nums[i]; ++j) {
                count[j] = min(count[j], count[i]+1);
            }
        }
        return count.back();
    }
};

class Solution_a {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<0) return INT_MAX;
        int nums_len = nums.size();
        int st_len =caculate_st_len(nums);
        int *st = construct_st_special(st_len);
        update_value(st, nums_len, nums_len-1, 0);
        for(int i=nums_len-2; i>=0; --i) {
            int target = nums[i] + i;
            int min_step = query_min_st(st, nums_len, i+1, target);
            if(nums[i]==0)  continue;
            //cout << "source, i:" << i << ", min_step: " << min_step << endl;
            //cout << "target: " << target << ", nums[i]: " << nums[i] << endl;
            //cout << "INT_MAX: " << INT_MAX << endl;
            if(min_step!=INT_MAX) update_value(st, nums_len, i, min_step+1);
        }
        return query_min_st(st, nums_len, 0, 0);
    }


    // [qs, qe]
    int caculate_st_len(vector<int>& nums) {
        return pow(2, ceil(log2(nums.size()))+1)-1;
    }
    int* construct_st_special(int st_len) {
        int* st = new int[st_len];
        for(int i=0; i<st_len; ++i) {
            st[i] = INT_MAX;
        }
        return st;
    }

    int query_min_st(int st[], int n, int qs, int qe) {
        return inner_query_min_st(st, 0, 0, n-1, qs, qe);   
    }
    int inner_query_min_st(int st[], int si, int ss, int se, int qs, int qe) {
        if(qs > se || qe < ss) return INT_MAX;
        if(qs <= ss && qe >= se) return st[si];

        int mid = (ss+se)/2;
        return min(inner_query_min_st(st, 2*si+1, ss, mid, qs, qe),
                    inner_query_min_st(st, 2*si+2, mid+1, se, qs, qe));
    }

    int update_value(int st[], int n, int qi, int value) {
        //cout << "qi: " << qi << ", " << value << endl;
        assert(value >= 0);
        inner_update_value(st, 0, 0, n-1, qi, value);
    }
    int inner_update_value(int st[], int si, int ss, int se, int qi, int value) {
        if(qi<ss || qi>se) return st[si];
        if(ss==se && ss==qi) {
            st[si] = value;
            return value;
        }
        int mid = (se+ss)/2;
        int left_min =  inner_update_value(st, si*2+1, ss, mid, qi, value);
        int right_min = inner_update_value(st, si*2+2, mid+1, se, qi, value);
        st[si] = min(left_min, right_min);
        return st[si];
    }
};

class Solution_b {
public:
    int jump(vector<int>& nums) {
        int can_reach = 0;
        int last_can_reach = 0;
        int count = 0;
        int i = 0;
        for(; i<nums.size() && i<=can_reach; ++i) {
            
            if(i>last_can_reach) {
                count += 1;
                last_can_reach = can_reach;
            }
            can_reach = max(can_reach, i + nums[i]);
        }
        return i==nums.size() ? count : INT_MAX;
    }
};

int main(int argc, char** argv) {

    vector<int> nums = {2,3,1,1,4};
    Solution s;
    Solution_a sa;
    Solution_b sb;

    cout << s.jump(nums) << endl;
    cout << sa.jump(nums) << endl;
    cout << sb.jump(nums) << endl;

    vector<int> nums_large;
    srandom(time(NULL));
    for(int i=0; i<10000; ++i){
        nums_large.push_back(abs(random())%50);
    }
    cout << s.jump(nums_large) << endl;
    cout << sa.jump(nums_large) << endl;
    cout << sb.jump(nums_large) << endl;

    vector<int> huge;
    for(int i=25000; i>2; i--) {
        huge.push_back(i);
    }
    cout << s.jump(huge) << endl;
    cout << sa.jump(huge) << endl;
    cout << sb.jump(huge) << endl;


    return 0;
}
