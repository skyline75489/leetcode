class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        long len = digits.size();
        int last_num = digits[len-1];
        if (last_num < 9) {
            digits[len-1] += 1;
            return digits;
        }
        digits[len-1] = 0;
        digits.insert(digits.begin(), 0);
        while (len--) {
            if (digits[len] < 9) {
                digits[len] += 1;
                break;
            } else {
                digits[len] = 0;
            }
        }
        if (digits[0] == 0) {
            digits.erase(digits.begin());
        }
        return digits;

    }
};