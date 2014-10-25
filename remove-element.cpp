class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        return distance(A, remove(A, A+n, elem));    
};