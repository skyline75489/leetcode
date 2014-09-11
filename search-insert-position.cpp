class Solution {
public:
    // 线性搜索也能过，看来leetcode的测试数据并不大
    int searchInsert(int A[], int n, int target) {
        if (target <= A[0]) {
            return 0;
        }
        for (int i=0; i<n; i++) {
            if (i == n-1) {
                return n;
            }
            if (A[i] <= target && target <= A[i+1]) {
                return i + 1;
            }
        }
        return 0;
    }
};

// 二分查找
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0, r = n - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (target == A[mid]) {
                return mid;
            } else if (target > A[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};