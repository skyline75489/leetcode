class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        long beginX = 0, endX = matrix[0].size() - 1;
        long beginY = 0, endY = matrix.size() - 1;
        
        while (true) {
            for (long i=beginX;i<=endX;i++) {
                result.push_back(matrix[beginY][i]);
            }
            if (++beginY > endY) {
                break;
            }
            for (long j=beginY; j<=endY; j++) {
                result.push_back(matrix[j][endX]);
            }
            if (--endX < beginX) {
                break;
            }
            for (long k=endX; k>=beginX; k--) {
                result.push_back(matrix[endY][k]);
            }
            if (--endY < beginY) {
                break;
            }
            for (long l=endY; l>=beginY; l--) {
                result.push_back(matrix[l][beginX]);
            }
            if (++beginX > endX) {
                break;
            }
        }
        return result;
    }
};