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
        stack<pair<pair<int,int>, vector<bool>>> find_route; 
       
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j]!='.') continue;
                vector<bool> usable_num = find_usable(board, i, j);
                //print_usable(usable_num, i, j);
                int selected = 0;
                while(selected<9 && !usable_num[selected]) ++selected;
                if(selected>=9){
                    // backtracking
                    while(!find_route.empty()){
                        auto prev_node = find_route.top();
                        find_route.pop();
                        vector<bool>& usable_num = prev_node.second;
                        int selected = 0;
                        while(selected<9 && !usable_num[selected]) ++selected;
                        i = prev_node.first.first;
                        j = prev_node.first.second;
                        board[i][j]='.';
                        if(selected>=9) continue;
                        //print_usable(usable_num, i, j);
                        usable_num[selected]=false;
                        board[i][j] = '1' + selected;
                        find_route.push(make_pair(make_pair(i,j), usable_num));
                        break;
                    }
                    if(find_route.empty()){
                        cout << "failed, why?" << endl;
                        return;
                    }
                    // here!
                    continue;
                }
                board[i][j]='1'+selected;
                usable_num[selected] = false;
                find_route.push(make_pair(make_pair(i,j), usable_num));
            }
        }

        return;
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
