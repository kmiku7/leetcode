#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size()==0) return 0;

        int grid[101][101] = {0};
        grid[0][1] = 1;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                if(obstacleGrid[i-1][j-1]==1) continue;
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m][n];
    }
};



int main(int argc, char** argv) {


    return 0;
}
