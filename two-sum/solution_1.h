#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> exist;
        vector<int> result(2);

        for(int i=0; i<numbers.size(); ++i) {
            exist[numbers[i]] = i;
        }

        for(int i=0; i<numbers.size(); ++i) {
            int remain = target - numbers[i];
            auto remain_iter = exist.find(remain);
            if(remain_iter != exist.end() && (*remain_iter).second != i) {
                result[0] = i+1;
                result[1] = (*remain_iter).second+1;
                return result;
            }
        }

        assert(0 && "SHOULD NOT REACH HERE");
        return result;
    }
};
