#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <iterator>
#include <vector>

using namespace std;

#define SOLUTION Solution_a

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size()<2) return 0;
        sort(num.begin(), num.end());
        int max_gap = 0;
        for(int i=1; i<num.size(); ++i) {
            max_gap = max(max_gap, num[i]-num[i-1]);
        }
        return max_gap;
    }
};

class Solution_a {
public:
    int maximumGap(vector<int> &num) {
        if(num.size()<=1) return 0;

        int ub = num[0];
        int lb = num[0];
        for(int val : num) {
            lb = min(lb, val);
            ub = max(ub, val);
        }
        if(lb==ub || num.size()==2) return ub-lb;

        int gap = (ub-lb+num.size()-1-1) / (num.size()-1);
        int interval_count = (ub-lb)/gap + 1;
        // filled(?), min, max
        int *interval_stat = (int*)malloc(sizeof(int)*3*interval_count);
        for(int i=0, end_guard=interval_count*3; i<end_guard; i+=3) {
            interval_stat[i] = 0;
            interval_stat[i+1] = ub;
            interval_stat[i+2] = lb;
        }

        for(int val : num) {
            int idx = (val-lb)/gap;
            idx = idx*3;
            interval_stat[idx] = 1;
            interval_stat[idx+1] = min(interval_stat[idx+1], val);
            interval_stat[idx+2] = max(interval_stat[idx+2], val);
        }

        int max_gap = 0;
        int prev = 0;
        for(int i=3, end_guard=interval_count*3; i<end_guard; i+=3) {
            if(!interval_stat[i]) continue;
            int this_gap = interval_stat[i+1] - interval_stat[prev+2];
            prev = i;
            max_gap = max(max_gap, this_gap);
        }
        return max_gap;
    }
};


int main(int argc, char** argv) {
    srandom(time(NULL));
///*
    vector<int> num;
    for(int i=0; i<100000; i++){
        num.push_back(random()%1000000);
    }
//*/
    //vector<int> num = {200, 6, 1};
    SOLUTION s;
    cout << s.maximumGap(num) << endl;

    return 0;
}
