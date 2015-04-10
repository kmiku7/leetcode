#include <vector>
using namespace std;


class Solution {
public:
    int rob(vector<int> &num) {
        if(num.size()==0) return 0;
        if(num.size()==1) return num[0];

        vector<int> result(num.size());
        result[0] = num[0];
        result[1] = num[1]>num[0]?num[1]:num[0];

        for(int i=2; i<num.size(); ++i){
            int rob = num[i] + result[i-2];
            result[i] = rob > result[i-1] ? rob : result[i-1];
        }
        return result.back();
    }
};
