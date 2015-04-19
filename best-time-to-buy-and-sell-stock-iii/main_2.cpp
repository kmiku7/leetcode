#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int *buffer = (int*)malloc(sizeof(int)*(prices.size()+1));
        memset(buffer,0,sizeof(int)*(prices.size()+1));

        int min_prices = INT_MAX;
        int max_prices = INT_MIN;
        int max_profit = 0;
        for(int i=0; i<prices.size(); ++i) {
            if(prices[i]<min_prices) {
                min_prices = prices[i];
            }
            buffer[i+1] = max(buffer[i], prices[i]-min_prices);
        }
        int total_max = buffer[prices.size()];
        for(int i=prices.size(); i>0; --i) {
            if(prices[i-1]>max_prices) {
                max_prices = prices[i-1];
            }
            max_profit = max(max_profit, max_prices-prices[i-1]);
            total_max = max(total_max, max_profit+buffer[i-1]);
        }
        return total_max;
    }
};


int main(int argc, char** argv) {

    vector<int> prices = {
        1,2};

    Solution s;

    cout << s.maxProfit(prices) << endl;

    return 0;
}
