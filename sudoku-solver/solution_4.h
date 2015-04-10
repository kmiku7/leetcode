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
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char> > &board, int row, int col) {
        if(row==8 && col==9) return true;

        row = row + col/9;
        col = col%9;

        if(board[row][col]!='.') return solve(board, row, col+1);

        vector<bool> usable_num = find_usable(board, row, col);
        //print_usable(usable_num, i, j);
        for(int selected=0; selected<9; ++selected){
            if(usable_num[selected]==false) continue;
            board[row][col] = '1' + selected;
            int ret = solve(board, row, col+1);
            if(ret) return ret;
        }
        board[row][col] = '.';

        return false;
    }

    vector<bool> find_usable(vector<vector<char>>& board, int y, int x){
        int base_x = (x/3)*3;
        int base_y = (y/3)*3;
        vector<bool> usable_num(9,true);
        for(int i=0; i<9; ++i){
            if(board[i][x] == '.') continue;
            usable_num[board[i][x]-'1'] = false;
        }
        for(int j=0; j<9; ++j){
            if(board[y][j] == '.') continue;
            usable_num[board[y][j]-'1'] = false;
        }
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if(board[base_y+i][base_x+j]=='.') continue;
                usable_num[board[base_y+i][base_x+j]-'1'] = false;
            }
        }
        return usable_num;
    }
};
