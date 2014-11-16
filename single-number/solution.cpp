
class Solution {
public:
    int singleNumber(int A[], int n) {
        int mark = 0;
        for (int i = 0; i < n; ++i) {
            mark ^= A[i];
        }
        return mark;
    }
};
