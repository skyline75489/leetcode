// 通过一个计数器来记录重复的次数
// 实现的比较丑陋
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        int index = 0;
        int times = 0;
        for (int i = 1; i < n; i++) {
            if (A[index] == A[i]) {
                if (times == 0) {
                    A[++index] = A[i];
                }
                times++;
            } else {
                A[++index] = A[i];
                times = 0;
            }
        }
        return index+1;      
    }
};