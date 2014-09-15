// 我写的代码实在太乱了，这个思路比我的清晰多了
class Solution {
public:
    int search(int A[], int n, int target) {
        int l,r,mid;
        l = 0, r = n-1;
        while (l<=r) {
            mid = (l + r) / 2;
            // 正中目标，直接返回
            if (A[mid] == target) {
                return mid;
            }
            // mid的位置在旋转后的序列的前一部分
            if (A[l] <= A[mid]) {
                // 如果target也在这前一部分，可以直接进行二分
                if (A[l] <= target && target < A[mid]) {
                    r = mid;
                // 如果target不在这一部分，可以通过改变l来改变搜索的范围
                // 最终会使得target进入一个递增序列，进行二分
                } else {
                    l = mid + 1;
                }
            // A[mid]比A[l]小，说明mid的位置超过了旋转点
            // 进入了后一部分序列
            } else {
                // 同上
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
