class Solution {
public:
    int findMin(vector<int> &num) {
        long l, mid, r;
        l = 0, r = num.size()-1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (num[l] <= num[mid]) {
                // 递增，没有旋转
                if (num[mid] <= num[r]) {
                    return num[l];
                } else {
                    l = mid + 1;
                }
            } else {
                r = mid;
            }
        }
        return num[l];
    }
};