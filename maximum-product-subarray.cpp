// 来自 https://oj.leetcode.com/discuss/17913/implementation-the-suggested-solution-dynamic-programming
class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n == 0){
            return 0;
        }
        int* maxArray = new int[n];
        int* minArray = new int[n];
        maxArray[0] = A[0];
        minArray[0] = A[0];
        int maxProduct = A[0];
        for(int i = 1; i < n; i++){
            if(A[i] > 0){
                maxArray[i] = max(maxArray[i - 1] * A[i], A[i]);
                minArray[i] = min(minArray[i - 1] * A[i], A[i]);
            }
            else{
                maxArray[i] = max(minArray[i - 1] * A[i], A[i]);
                minArray[i] = min(maxArray[i - 1] * A[i], A[i]);
            }
            maxProduct = max(maxProduct, maxArray[i]);
        }
        return maxProduct;
    }
};