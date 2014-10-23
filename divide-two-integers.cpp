class Solution {
public:
    int divide(int dividend, int divisor) {
        long long result = 0;
        // 必须用long long，否则在INT_MIN会溢出
        long long a = dividend > 0 ? dividend : -(long long)dividend;
        long long b = divisor > 0 ? divisor : -(long long)divisor;
        long long c = 0;
        while (a>=b) {
            c = b;
            // 让减去的除数加倍，加快计算速度
            for (int i = 0; a >= c; i++, c <<= 1) {
                a -= c;
                result += 1 << i;
            }
        }
        return ((dividend^divisor)>>31) ? (-result) : result;
    }
};