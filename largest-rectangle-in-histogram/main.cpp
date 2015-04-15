#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// Time Limit Exceeded
// n^2，tle
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int max_area = 0;
        vector<int> min_height(height.size(), INT_MAX);
        for(int cover=0; cover<height.size(); ++cover) {
            for(int begin=0; begin<height.size(); ++begin) {
                min_height[begin] = min(min_height[begin], height[begin+cover]);
                max_area = max(max_area, min_height[begin]*(cover+1));
            }
        }
        return max_area;
    }
};


// divide and conquer
// 全部height相同，退化为n^2, tle
class Solution_a {
public:
    int largestRectangleArea(vector<int>& height) {
        return divide(height, 0, height.size());   
    }
    // [begin, end)
    int divide(vector<int>& height, int begin, int end){
        if(begin>=end) return 0;
        int min_pos = begin;
        int min_val = INT_MAX;
        for(int i=begin; i<end; ++i) {
            //if(height[i]<min_val) { 这行代码在case里有INT_MAX时导致出core。
            if(height[i]<=min_val) {
                min_val = height[i];
                min_pos = i;
            }
        }
        return max(min_val*(end-begin), 
                    max(divide(height, begin, min_pos), divide(height, min_pos+1, end)));
    }
};

class Solution_b {
public:
    int* construct_st(vector<int>& height) {
        int st_len = pow(2, ceil(log2(height.size()))+1) - 1;
        int* st = new int[st_len];
        inner_construct_st(height, 0, height.size()-1, st, 0);
        return st;
    }
    int inner_construct_st(vector<int>& height, int begin, int end, int st[], int si) {
        if(begin==end) {
            st[si] = begin;
            return begin;
        }
        int mid = (begin+end)/2;
        int left_min_pos = inner_construct_st(height, begin, mid, st, 2*si+1);
        int right_min_pos = inner_construct_st(height, mid+1, end, st, 2*si+2);
        st[si] = height[left_min_pos] <= height[right_min_pos] ? left_min_pos : right_min_pos;
        return st[si];
    }
    //void destruct_st(int* st);
    // [begin, end)
    int query_min_pos(int* st, vector<int>& height, int begin, int end) {
        if(end<0 || begin>=height.size()) {
            assert(false && "caller should check this stat.");
            return -1;
        }
        return inner_query_min_pos(st, 0, (int)height.size()-1, 0, begin, end, height);
    }

    int inner_query_min_pos(int st[], int ss, int se, int si, int begin, int end, vector<int>& height) {
        if(begin<=ss && end>=se) {
            return st[si];
        }
        if(begin>se || end<ss) return -1;
        int mid = (se+ss)/2;
        int left_min_pos = inner_query_min_pos(st, ss, mid, 2*si+1, begin, end, height);
        int right_min_pos = inner_query_min_pos(st, mid+1, se, 2*si+2, begin, end, height);
        if(left_min_pos != -1 && right_min_pos != -1) {
            return height[left_min_pos] <= height[right_min_pos] ? left_min_pos : right_min_pos;
        }
        return left_min_pos != -1 ? left_min_pos : right_min_pos;
    }

    int largestRectangleArea(vector<int>& height) {
        if(height.size()<=0) return 0;
        int *st = construct_st(height);
        return divide(height, 0, height.size(), st);
        //destruct_st(st);
    }

    // [begin, end)
    int divide(vector<int>& height, int begin, int end, int st[]) {
        if(begin>=end) return 0;
        int min_pos = query_min_pos(st, height, begin, end-1);
        return max(height[min_pos]*(end-begin),
                    max(divide(height, begin, min_pos, st),
                        divide(height, min_pos+1, end, st)));
    }
};

// http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
class Solution_c {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> stack;
        int max_area = 0;
        stack.reserve(height.size());
        int i=0;
        while(i<height.size()) {
            if(stack.empty() || height[i]>=height[stack.back()]) {
                stack.push_back(i++);
            } else {
                int tp = stack.back();
                stack.pop_back();
                int temp_area = height[tp] * (stack.empty() ? i : i - stack.back() - 1);
                if(temp_area > max_area) max_area = temp_area;
            }
        }
        while(!stack.empty()){
            int tp = stack.back();
            stack.pop_back();
            int temp_area = height[tp] * (stack.empty() ? i : i - stack.back() - 1);
            if(temp_area > max_area) max_area = temp_area;
        }
        return max_area;
    }
};

int main(int argc, char** argv) {

    //vector<int> height = {0};
    //vector<int> height = {2,1,5,6,2,3};
    vector<int> height = {0,0,0,0,0,0,0,0,2147483647};
    Solution s;
    Solution_a s_dc;
    Solution_b s_dc_st;
    Solution_c s_l;
    cout << s.largestRectangleArea(height) << endl;
    cout << s_dc.largestRectangleArea(height) << endl;
    cout << s_dc_st.largestRectangleArea(height) << endl;
    cout << s_l.largestRectangleArea(height) << endl;

    return 0;
}
