// http://fisherlei.blogspot.com/2013/03/leetcode-search-2d-matrix-solution.html
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int col = matrix[0].size();
        int row = matrix.size();

        int begin, end;

        begin = 0;
        end = row;
        while(begin<end){
            int mid = (begin+end)/2;
            if(target<matrix[mid][0])
                end = mid;
            else
                begin = mid+1;
        }
        --begin;
        if(begin<0 || matrix[begin][0]>target) return false;
        if(matrix[begin][0]==target) return true;

        row = begin;
        begin = 0;
        end = col;
        while(begin<end){
            int mid = (begin+end)/2;
            if(target<matrix[row][mid])
                end = mid;
            else
                begin = mid + 1;
        }
        --begin;
        return begin>=0 && matrix[row][begin]==target;
    }
};

int main(int argc, char** argv){

    vector<vector<int>> m = {
            {1,     3,  5,  7},
            {10,    11, 16, 20},
            {23,    30, 34, 50}};

    Solution s;

    cout << s.searchMatrix(m, 0) << endl;
    cout << s.searchMatrix(m, 3) << endl;
    cout << s.searchMatrix(m, 4) << endl;
    cout << s.searchMatrix(m, 400) << endl;

    return 0;

}
