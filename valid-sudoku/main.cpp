#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool sub_block_mask[9][9] = {{false}};
        bool cols_mask[9][9] = {{false}};
        for(int i=0; i<9; ++i) {
            auto &line = board[i];
            bool line_mask[9] = {false};
            for(int j=0; j<9; ++j) {
                if(line[j]!='.') {
                    char c =line[j]-'1';
                    int sub_block_idx = (i/3)*3 + j/3;
                    if(line_mask[c] || cols_mask[j][c] || sub_block_mask[sub_block_idx][c]) return false;
                    line_mask[c] = true;
                    cols_mask[j][c] = true;
                    sub_block_mask[sub_block_idx][c] = true;
                }
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {

    if(argc!=2){
        cout<< "a.out filename" << endl;
        return 1;
    }

    ifstream fin(argv[1]);
    if(!fin){
        cout << "open file failed" << endl;
        return 2;
    }

    vector<vector<char>> board;

    while(true){
        string temp;
        fin >> temp;
        if(!fin){
            break;
        }
        if(temp.length()!=9){
            cout << "invalid line: " << temp << endl;
            return 3;
        }

        board.push_back(vector<char>(temp.begin(), temp.end()));
    }
    if(board.size()!=9){
        cout << "invalid file: " << argv[1] << endl;
        return 4;
    }

    Solution s;

    cout << s.isValidSudoku(board) << endl;

    return 0;
}
