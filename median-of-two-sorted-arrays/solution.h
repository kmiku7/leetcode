#include <cstdlib>
#include <cstddef>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int mid_left = (m+n-1)/2;
        int mid_right = (m+n)/2;
        int *merged = (int*)malloc(sizeof(int)*(mid_right+1));

        int a_idx = 0;
        int b_idx = 0;
        int m_idx = 0;

        while(a_idx<m && b_idx<n && m_idx<=mid_right) {
            if(A[a_idx]<B[b_idx]){
                merged[m_idx++] = A[a_idx++];
            } else {
                merged[m_idx++] = B[b_idx++];
            }
        }

        while(a_idx<m && m_idx<=mid_right) {
            merged[m_idx++] = A[a_idx++];
        }

        while(b_idx<n && m_idx<=mid_right) {
            merged[m_idx++] = B[b_idx++];
        }

        double mid = (merged[mid_left] + merged[mid_right])/2.0;
        free(merged);
        merged = NULL;
        return mid;
    }
};
