class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int j = n-1;
        while ( i <= j ) {
            if (A[i] == elem) {
                while (A[j] == elem) {
                    j--;
                }
            }
            else {
                while (A[i] != elem && i<=j) {
                    i++;
                }
                while (A[j] == elem) {
                    j--;
                }
            }
            if (i < j) {
                swap(A[i], A[j]);
            }
        }
        return j+1;
    }
};