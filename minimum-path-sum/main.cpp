#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;

        vector<int> partial_sum(grid[0].size(),0);
        partial_sum[0] = grid[0][0];
        int line_num = grid.size();
        int col_num = grid[0].size();

        for(int i=1; i<col_num; ++i) {
            partial_sum[i] = partial_sum[i-1] + grid[0][i];
        }
        for(int i=1; i<line_num; ++i) {
            partial_sum[0] += grid[i][0];
            for(int j=1; j<col_num; ++j) {
                partial_sum[j] = grid[i][j] + min(partial_sum[j], partial_sum[j-1]);
            }
        }
        return partial_sum.back();
    }
};


int main(int argc, char** argv) {
    return 0;

}
