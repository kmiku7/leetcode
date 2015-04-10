#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if(grid[i][j]=='1'){
                    mask(grid, i, j);
                    ++count;
                }
            }
        }
        return count;          
    }
    void mask(vector<vector<char>>&grid, int x, int y){
        if(grid[x][y]!='1') return;
        grid[x][y] = '2';
        if(x>0)
            mask(grid, x-1, y);
        if(x+1<grid.size())
            mask(grid, x+1, y);
        if(y>0)
            mask(grid, x, y-1);
        if(y+1<grid[0].size())
            mask(grid, x, y+1);
    }
};
