// STL大法好，C++11大法好
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        vector<int> temp;
        temp.push_back(target);
        vector<vector<int>>::iterator Iter1 =  lower_bound(matrix.begin(), matrix.end(), temp, [](vector<int> a, vector<int> b){return a[0] <= b[0];
    });
        if (!(Iter1 == matrix.begin())) {
            Iter1 --;
        }
        
        vector<int> row = *Iter1;
        return binary_search(row.begin(), row.end(), target);
    }
};