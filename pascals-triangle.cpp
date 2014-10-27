class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        for (int i=0; i<numRows; i++) {
            vector<int> v;
            v.push_back(1);
            if (numRows == 1) {
                result.push_back(v);
                break;
            }
            if (i == 0) {
                result.push_back(v);
                continue;
            }
            for (int j=1; j<i; j++) {
                v.push_back(result[i-1][j-1] + result[i-1][j]);
            }
            v.push_back(1);
            result.push_back(v);
        }
        return result;
    }
};