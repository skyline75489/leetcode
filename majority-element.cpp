class Solution {
public:
    int majorityElement(vector<int> &num) {
        int len = num.size();
        int count = 0;
        int target;
        for (int i = 0; i < len; ++i) {
            if (count == 0) {
                target = num[i];
                count = 1;
            } else {
                if (target == num[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return target;
    }
};