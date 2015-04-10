

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        swap(nums, 0, n);
        swap(nums, k, n);
        swap(nums, 0, k);
    }

    void swap(int nums[], int begin, int end) {
        int* head_pos = nums+begin;
        int* tail_pos = nums+end-1;
        while(head_pos < tail_pos) {
            int temp = *head_pos;
            *(head_pos++) = *tail_pos;
            *(tail_pos--) = temp;
        }
    }
};


