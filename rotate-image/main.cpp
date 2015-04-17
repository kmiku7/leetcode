#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int line_num = matrix.size();
        int line_ub = line_num/2;
        for(int i=0; i<line_ub; ++i) {
            for(int j=i; j<line_num-i-1; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[line_num-j-1][i];
                matrix[line_num-j-1][i] = matrix[line_num-i-1][line_num-j-1];
                matrix[line_num-i-1][line_num-j-1] = matrix[j][line_num-i-1];
                //matrix[line_num-j-1][i] = matrix[i][j];
                matrix[j][line_num-i-1] = temp;
            }
        }
    }
};


int main(int argc, char** argv) {
    vector<vector<int>> m {
        {1,2,3},
        {4,5,6},
        {7,8,9}};
    Solution s;
    s.rotate(m);
    for(auto v : m) {
        for(auto i : v) {
            cout << i << ", ";
        }
        cout << endl;
    }

    return 0;
}
