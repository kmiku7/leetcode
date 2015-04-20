#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int grid[101][101] = {0};
        grid[0][1] = 1;

        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                grid[i][j] = grid[i][j-1] + grid[i-1][j];
            }
        }
        return grid[m][n];       
    }
};


int main(int argc, char** argv) {

    Solution s;
    cout << s.uniquePaths(2,3) << endl;


    return 0;
}
