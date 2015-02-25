class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int buffer = 0;
        for (int i=0; i<k; i++) {
            buffer = nums[n-1];
            for (int j=n-2; j >= 0; j--) {
                nums[j+1] = nums[j];
            }
            nums[0] = buffer;
        }
    }
};