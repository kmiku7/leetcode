#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;

        vector<int> histogram_len(matrix[0].size(), 0);
        vector<int> stack;
        stack.reserve(histogram_len.size());

        int max_area = 0;

        for(auto &line : matrix) {
            for(int i=0; i<line.size(); ++i) {
                histogram_len[i] = 
                    (line[i]=='1' ? (histogram_len[i]+1) : 0);
            }
            int i = 0;
            while(i<line.size()) {
                if(stack.empty() || histogram_len[i] >= histogram_len[stack.back()]) {
                    stack.push_back(i++);
                } else {
                    int tp = stack.back();
                    stack.pop_back();
                    int temp_area = histogram_len[tp] * (stack.empty() ? i : (i-stack.back()-1));
                    if(temp_area>max_area) max_area = temp_area;
                }
            }
            while(!stack.empty()) {
                int tp = stack.back();
                stack.pop_back();
                int temp_area = histogram_len[tp] * (stack.empty() ? i : (i-stack.back()-1));
                if(temp_area>max_area) max_area = temp_area;
            }
        }
        return max_area;
    }
};


int main(int argc, char** argv) {


    ifstream fin(argv[1]);
    if(!fin) {
        cout << "open failed" << endl;
        return 1;
    }

    vector<vector<char>> matrix;

    string line;
    while(true){
        fin >> line;
        if(!fin) break;
        if(matrix.empty() || matrix[0].size() == line.size()) {
            cout << line << endl;
            matrix.push_back(vector<char>(line.begin(), line.end()));
        } else {
            cout << "invalid input" << endl;
            return 2;
        }
    }

    Solution s;
    cout << s.maximalRectangle(matrix) << endl;
    

    return 0;
}
