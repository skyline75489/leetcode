class Solution {
public:
    int maxSubArray(int A[], int n) {
        int result = INT_MIN, f = 0;
        for (int i=0; i < n; i++) {
            f = max(f + A[i], A[i]);
            result = max(result, f);
        }
        return result;
    }
};