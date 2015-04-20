#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size()==1) return triangle[0][0];
        vector<int> min_value(triangle.back().begin(), triangle.back().end());

        for(int i=(int)triangle.size()-2; i>=0; --i) {
            for(int j=0; j<triangle[i].size(); ++j) {
                min_value[j] = min(min_value[j], min_value[j+1]) + triangle[i][j];
            }
        }
        return min_value[0];
    }
};


int main(int argc, char** argv) {

    Solution s;
    vector<vector<int>> tri = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };
    cout << s.minimumTotal(tri) << endl;

    return 0;
}
