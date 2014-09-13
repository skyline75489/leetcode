// 我写的代码实在太乱了，这个思路比我的清晰多了
class Solution {
public:
    int search(int A[], int n, int target) {
        int l,r,mid;
        l = 0, r = n-1;
        while (l<=r) {
            mid = (l + r) / 2;
            if (A[mid] == target) {
                return mid;
            }
            if (A[l] <= A[mid]) {
                if (A[l] <= target && target < A[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                if (A[mid] < target && target <= A[r]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
        return -1;
    }
};