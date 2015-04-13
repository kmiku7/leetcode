#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;

        int curr_min_price = prices[0];
        int max_profit = 0;
        for(auto price : prices){
            if(price<curr_min_price) {
                curr_min_price = price;
            }
            max_profit = max(max_profit, price - curr_min_price);
        }
        return max_profit;
    }
};


int main(int argc, char** argv) {

    vector<int> prices = { 5, 4, 3, 4, 5, 6, 7, 8, 6, 3, 1, 5};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;

}
