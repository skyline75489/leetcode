class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        long n = matrix.size();
        for (int j=0; j * 2 < n; j++) {
            for (int i=j; i<n-1-j; i++) {
                swap(matrix[j][i], matrix[i][n-1-j]);
                swap(matrix[n-1-i][j], matrix[j][i]);
                swap(matrix[n-1-j][n-1-i], matrix[n-1-i][j]);
            }
        }
    }
};