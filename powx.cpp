class Solution {
public:
    double pow(double x, int n) {
        // 指数为负
        if (n < 0)
            return 1.0 / power(x, n);
        else
            return power(x, n);
    }
private:
    // 二分法,xn = xn/2 × xn/2 × xn%2
    double power(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double v = power(x, n / 2);
        if (n % 2 == 0) {
            return v * v;
        }
        else{
            return v * v * x;
        }
    }
};