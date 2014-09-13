// STL 大法好
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        return std::distance(A, std::unique(A, A+n));
    }
};