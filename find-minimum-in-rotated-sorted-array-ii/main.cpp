class Solution {
public:
    int findMin(vector<int> &num) {
        int min_val = INT_MAX;
        int prev_val = INT_MIN;
        for(auto val : num) {
            min_val = min(min_val, val);
            if(val < prev_val) break;
            prev_val = val;
        }
        return min_val;      
    }
};
