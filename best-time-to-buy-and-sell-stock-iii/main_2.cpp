#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {

        if(prices.size()<=1 || k<=0) return 0;

        int profit_sum = 0;
        int k = 2;

        vector<int> prev_day(prices.size()+1, 0);
        vector<int> curr_day(prices.size()+1);

        int loop_count = min(k*2, prices.size()&~0x1);
        for(int i=0; i<loop_count; ++i) {
            // buy or sell
            int op = ((i&0x1)==0 ? -1 : 1);
            curr_day[i] = INT_MIN;
            for(int j=i+1; j<==prices.size(); ++j) {
                curr_day[j] = max(curr_day[j-1], prev_day[j]+prices[j-1]);
            }
        }



        return profit_sum;
    }
};


int main(int argc, char** argv) {

    vector<int> prices = {
        1,7,2,4};

    Solution s;

    cout << s.maxProfit(prices) << endl;

    return 0;
}
