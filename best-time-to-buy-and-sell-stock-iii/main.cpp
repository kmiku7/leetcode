#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> ACTION;
typedef vector<ACTION> TRANSACTIONS;

void print_actions(TRANSACTIONS& actions){
    for(auto& action:actions){
        cout << "ACTION: " << action.first << " " << action.second.first << " " << action.second.second << endl;
    }
}

bool action_cmp(ACTION& left, ACTION& right) {
    return abs(left.first) < abs(right.first);
}

class Solution {
public:
    int maxProfit(vector<int> &prices) {

        TRANSACTIONS usable_transactions;
        int profit_sum = 0;
        int k = 3;

        insert_up_edge(usable_transactions, prices, 0, prices.size());
        for(int i=0; i<k && !usable_transactions.empty(); ++i) {
            print_actions(usable_transactions);
            pop_heap(usable_transactions.begin(), usable_transactions.end(), action_cmp);
            auto action = usable_transactions.back();
            usable_transactions.pop_back();
            profit_sum += abs(action.first);
            if(action.first < 0) {
                insert_up_edge(usable_transactions, prices, action.second.first, action.second.second);
            } else {
                insert_down_edge(usable_transactions, prices, action.second.first, action.second.second);
            }
        }
        return profit_sum;
    }

    // 写不下去了， 这两个函数处理比较繁琐。
    void insert_up_edge(TRANSACTIONS& actions, vector<int>& prices, int begin, int end) {
    }

    void insert_down_edge(TRANSACTIONS& actions, vector<int>& prices, int begin, int end) {
    }
};


int main(int argc, char** argv) {

    vector<int> prices = {
        1,7,2,4};

    Solution s;

    cout << s.maxProfit(prices) << endl;

    return 0;
}
