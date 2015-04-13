#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

using namespace std;

class Solution {
public:
/*
 *  效果不大。
 *
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;

        int min_price = prices[0];
        int max_profit_sum = 0;
        int prices_size = prices.size();
        for(int i=1; i<prices_size; ++i) {
            while(prices[i]<=prices[i-1] && i<prices_size) ++i;
            min_price = prices[i-1];
            while(prices[i]>=prices[i-1] && i<prices_size) ++i;
            max_profit_sum += prices[i-1] - min_price;
        }

        return max_profit_sum;
    }
*/
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;

        int min_price = prices[0];
        int max_profit_sum = 0;
        for(int i=1; i<prices.size(); ++i) {
            while(prices[i]<=prices[i-1] && i<prices.size()) ++i;
            min_price = prices[i-1];
            while(prices[i]>=prices[i-1] && i<prices.size()) ++i;
            max_profit_sum += prices[i-1] - min_price;
        }

        return max_profit_sum;
    }
};


int main(int argc, char** argv) {

    vector<int> prices = { 5, 4, 3, 4, 5, 6, 7, 8, 6, 3, 1, 5};
    for(int i=0; i<100000; ++i) {
        prices.push_back(abs(random()%100));
    }
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;

}
