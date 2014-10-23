class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2) {
            return findKth(A, m, B, n, (total + 1)/2);
        } else {
            return (findKth(A, m, B, n, total/2) + findKth(A, m, B, n, total/2 + 1)) /2.0 ;
        }
    }
    // 在两个数组中寻找第k大的数
    int findKth(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return findKth(B, n, A, m, k);
        }
        if (m==0) {
            return B[k-1];
        }
        if (k==1) {
            return min(A[0], B[0]);
        }
    
        int mid1 = min(k/2, m);
        int mid2 = k - mid1;
        if (A[mid1-1] < B[mid2-1]) {
            return findKth(A + mid1, m - mid1, B, n, k - mid1);
        } else if (A[mid1-1] > B[mid2-1]) {
            return findKth(A, m , B+mid2, n-mid2, k-mid2);
        } else {
            return A[mid1-1];
        }
    }
};