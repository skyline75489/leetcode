class Solution {
public:
    bool search(int A[], int n, int target) {
        int l,r,mid;
        l = 0, r = n-1;
        while (l<=r) {
            mid = (l + r) / 2;
            if (A[mid] == target) {
                return true;
            }
            if (A[l] < A[mid]) {
                if (A[l] <= target && target < A[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else if (A[l] > A[mid]) {
                if (A[mid] < target && target <= A[r]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                l++;
            }
        }
        return false;
    }
};