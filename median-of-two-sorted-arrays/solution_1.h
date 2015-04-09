#include <cstdlib>
#include <cstddef>

#include <iostream>


using namespace std;


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int mid = (m+n)/2;
        if((m+n)&0x1){
            return findKthItem(A, m, B, n, mid+1);
        } else {
            return (findKthItem(A, m, B, n, mid) + findKthItem(A, m, B, n, mid+1))/2.0;
        }
    }

    int findKthItem(int A[], int m, int B[], int n, int k) {
        if(m==0) return B[k-1];
        if(n==0) return A[k-1];
        int a_mid = m/2;
        int b_mid = n/2;
        if(A[a_mid]<B[b_mid]) {
            if(k == a_mid+b_mid+2) {
                return findKthItem(A+a_mid+1, m-a_mid-1, B, b_mid+1, k-a_mid-1);
            } else if(k > a_mid+b_mid+2) {
                return findKthItem(A+a_mid+1, m-a_mid-1, B, n, k-a_mid-1);
            } else {
                return findKthItem(A, m, B, b_mid, k);
            }
        } else {
            if(k == a_mid+b_mid+2) {
                return findKthItem(A, a_mid+1, B+b_mid+1, n-b_mid-1, k-b_mid-1);
            } else if(k > a_mid+b_mid+2) {
                return findKthItem(A, m, B+b_mid+1, n-b_mid-1, k-b_mid-1);
            } else {
                return findKthItem(A, a_mid, B, n, k);
            }
        }
    }
};
