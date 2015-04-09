#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max = 0;
        for(int i=0, upper_bound=height.size(); i<upper_bound; ++i) {
            for(int j=i+1; j<upper_bound; ++j) {
                int tmp_container = (j-i)*(height[j]<height[i]?height[j]:height[i]);
                if(tmp_container>max){
                    max = tmp_container;
                }
            }
        }
        return max;
    }
};
