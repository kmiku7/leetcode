#include "Solution.h"

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;



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

    s.solveSudoku(board);

    for(auto line = board.begin(); line != board.end(); ++line) {
        for(auto row = (*line).begin(); row != (*line).end(); ++row){
            cout << *row;
        }
        cout << endl;
    }   
    return 0;
}
