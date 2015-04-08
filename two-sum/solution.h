#include <algorithm>
#include <vector>

using namespace std;

bool compare_pair(pair<int, int> left, pair<int, int> right) {
    return left.first < right.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int> > index_wrapper(numbers.size());
        for(int i = 0; i < index_wrapper.size(); ++i) {
            index_wrapper[i] = make_pair(numbers[i], i);
        }

        sort(index_wrapper.begin(), index_wrapper.end(), compare_pair);

        vector<pair<int, int> >::iterator head = index_wrapper.begin();
        vector<pair<int, int> >::iterator tail = index_wrapper.end() - 1;

        while(head < tail) {
            int sum = head->first + tail->first;
            if(sum == target) {
                break;
            } else if(sum < target) {
                head += 1;
            } else {
                tail -= 1;
            }
        }
        vector<int> result(2);
        result[0] = 1 + (head->second < tail->second ? head->second : tail->second);
        result[1] = 1 + (head->second > tail->second ? head->second : tail->second);

        return result;
    }
};
