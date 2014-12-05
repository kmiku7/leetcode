#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

vector<vector<int>> build_case() {
    int a[] = {
            0, 1, 1, 1, 1, 1, 1, 1,
            2, 2, 2, 2, 0, 2, 2, 2,
            3, 3, 3, 3, 3, 3, 3, 3,
            4, 4, 4, 0, 4, 4, 4, 4,
    };
    int row = 4;

    int col = sizeof(a) / sizeof(int) / row;
    vector<vector<int>> test_case;
    for (int i = 0; i < row; ++i) {
        vector<int> row(a+i*col, a+(i+1)*col);
        test_case.push_back(row);
    }
    return test_case;
}

void print_matrix(vector<vector<int>>& matrix) {
    for (auto iter = matrix.begin(); iter != matrix.end(); ++iter) {
        copy((*iter).begin(), (*iter).end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
}



class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int selected_row = -1;
        int selected_col = -1;

        for (int i = 0; i < matrix.size(); ++i) {
            vector<int>& row = matrix[i];
            for (int j = 0; j < row.size(); ++j) {
                if (row[j] == 0) {
                    selected_row = i;
                    selected_col = j;
                    goto FOR_OUT;
                }
            }
        }
        FOR_OUT:
        if (selected_row == -1 || selected_col == -1) {
            return;
        }

        for (int i = selected_row + 1; i < matrix.size(); ++i) {
            vector<int>& row = matrix[i];
            for (int j = 0; j < row.size(); ++j) {
                if (row[j] == 0) {
                    matrix[selected_row][j] = 0;
                    matrix[i][selected_col] = 0;
                }
            }
        }

        for (int i = selected_row + 1; i < matrix.size(); ++i) {
            if (matrix[i][selected_col] != 0) {
                continue;
            }
            for (auto iter = matrix[i].begin(); iter != matrix[i].end(); ++iter) {
                *iter = 0;
            }
        }

        for (int i = 0; i < matrix[0].size(); ++i) {
            if (matrix[selected_row][i] != 0) {
                continue;
            }
            for (auto iter = matrix.begin(); iter != matrix.end(); ++iter) {
                (*iter)[i] = 0;
            }
        }

        for(auto iter = matrix[selected_row].begin(); iter != matrix[selected_row].end(); ++iter) {
            *iter = 0;
        }
    }
};





int main() {

    auto test_case = build_case();
    Solution ss;
    cout << "----- before -----" << endl;
    print_matrix(test_case);

    ss.setZeroes(test_case);

    cout << "----- end -----" << endl;
    print_matrix(test_case);

    return 0;
}