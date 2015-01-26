class Solution {
public:
    string addBinary(string a, string b) {
        size_t size_a = a.size();
        size_t size_b = b.size();
        size_t size_r = size_a > size_b ? size_a : size_b;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result;
        int carry = 0;
        for (size_t i=0; i<size_r; i++) {
            int val_a = i < size_a ? a[i] - '0' : 0;
            int val_b = i < size_b ? b[i] - '0' : 0;
            int val = (val_a + val_b + carry) % 2;
            carry = (val_a + val_b + carry) / 2;
            result.insert(result.begin(), val+'0');
        }
        if (carry == 1) {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};