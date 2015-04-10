#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>
#include <cstdio>

using namespace std;

void print_usable(vector<bool>& u, int x, int y){
    printf("(%d,%d) ", x, y);
    for(auto iter = u.begin(); iter != u.end(); ++iter){
        cout << *iter;
    }
    cout << endl;
}

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0);
        return;
    }


    bool solve(vector<vector<char>>& board, int idx) {
        if(idx==81) return true;

        int x = idx % 9;
        int y = idx / 9;
        int base_x = (x/3)*3;
        int base_y = (y/3)*3;

        if(board[y][x]!='.') {
            return solve(board, idx+1);
        } else {
            vector<bool> mask(9, false);
            for(int i=0; i<9; ++i) {
                char in_line = board[y][i];
                char in_row = board[i][x];
                char in_block = board[base_y+(i/3)][base_x+(i%3)];
                if(in_line!='.') mask[in_line-'1'] = true;
                if(in_row!='.') mask[in_row-'1'] = true;
                if(in_block!='.') mask[in_block-'1'] = true;
            }
            for(int i=0; i<9; i++){
                if(mask[i]) continue;
                board[y][x]='1'+i;
                int ret = solve(board, idx+1);
                if(ret) return true;
            }
            board[y][x] = '.';
            return false;
        }
    }
};
