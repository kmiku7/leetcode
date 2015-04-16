#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class Solution {
public:
    int totalNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        int stat[n*n];
        memset(stat, 0, sizeof(int)*n*n);
        return fill_line(grid, 0, stat, n);
    }

    int fill_line(vector<string>& grid, int line, int stat[], int n) {
        // assert(line<n);
        int (*grid_stat)[n] = (int(*)[n])stat;
        auto &grid_line = grid[line];
        int count = 0;
        for(int i=0; i<n; ++i) {
            if(grid_stat[line][i]!=0) continue;

            grid_line[i] = 'Q';
            // mask
            for(int j=1; j+line<n; ++j) {
                if(i-j>=0) grid_stat[line+j][i-j] += 1;
                if(i+j<n)  grid_stat[line+j][i+j] += 1;
                grid_stat[line+j][i] += 1;
            }
            if(line<n-1) count += fill_line(grid, line+1, stat, n);
            else count += 1;

            grid_line[i] = '.';
            // unmask
            for(int j=1; j+line<n; ++j) {
                if(i-j>=0) grid_stat[line+j][i-j] -= 1;
                if(i+j<n)  grid_stat[line+j][i+j] -= 1;
                grid_stat[line+j][i] -= 1;
            }
        }
        return count;
    }
};



int main(int argc, char** argv) {

    int n = 4;
    if(argc>1) {
        n = atoi(argv[1]);
    }

    Solution s;
    auto result = s.totalNQueens(n);
    cout << n << ", " << result << endl;
    return 0;
}
