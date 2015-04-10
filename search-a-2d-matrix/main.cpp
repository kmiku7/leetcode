#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int col = matrix[0].size()-1;
        int row = 0;
        while(row<matrix.size() && col>=0){
            if(target==matrix[row][col])
                return true;
            if(target<matrix[row][col]){
                --col;
            } else {
                ++row;
            }
        }
        return false;
    }
};

int main(int argc, char** argv){

    vector<vector<int>> m = {
            {1,     3,  5,  7},
            {10,    11, 16, 20},
            {23,    30, 34, 50}};

    Solution s;

    bool ret = s.searchMatrix(m, 3);
    cout << ret << endl;

    return 0;

}
