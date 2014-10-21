class Solution {
public:
    int sqrt(int x) {
        if (x < 2) {
            return x;
        }
        int l, m, r, lm;
        l = 1;
        r = x / 2;
        m = 1;
        lm = 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (x / m == m) {
                return m;
            }
            if (x / m < m) {
                r = m - 1;
            }
            if (x / m > m) {
                l = m + 1;
                lm = m;
            }
        }
        return lm;
    }
};