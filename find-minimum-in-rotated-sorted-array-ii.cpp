class Solution {
public:
    int findMin(vector<int> &num) {
           long l, mid, r;
            l = 0, r = num.size()-1, mid = 0;
            while (l + 1 < r) {
                mid = (l + r) / 2;
                if (num[l] < num[r]) {
                    return num[l];
                } else if (num[l] > num[r]) {
                    if (num[mid] >= num[l]) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                } else {
                    l++;
                }
            }
            return min(num[l], num[r]);
    }
};