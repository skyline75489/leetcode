class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int begin = 0, end = n-1;
        int num = 1;
        while (begin < end) {
            for (int i=begin; i<end; i++) {
                matrix[begin][i] = num++;
            }
            for (int j=begin; j<end; j++) {
                matrix[j][end] = num++;
            }
            for (int k=end; k>begin; k--) {
                matrix[end][k] = num++;
            }
            for (int l=end; l>begin; l--) {
                matrix[l][begin] = num++;
            }
            begin++;
            end--;
        }
        if (begin == end) {
            matrix[begin][begin] = num;
        }
        return matrix;
    }
};