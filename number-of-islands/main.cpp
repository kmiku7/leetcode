#include <iostream>
#include <fstream>
#include "solution.h"

using namespace std;


int main(int argc, char** argv){

    if(argc!=2){
        cout << "a.out filename" << endl;
        return 1;
    }

    ifstream fin(argv[1]);
    if(!fin){
        cout << "open file failed" << endl;
        return 2;
    }

    vector<vector<char>> cases;
    while(1){
        string temp;
        fin >> temp;
        if(!fin)break;
        cases.push_back(vector<char>(temp.begin(), temp.end()));
        cout << temp << endl;
    }

    Solution s;
    int count = s.numIslands(cases);
    cout << count << endl;

    return 0;

}
