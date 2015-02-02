/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    template <typename RandomAccessIterator>
    TreeNode *sortedArrayToBST(RandomAccessIterator begin, RandomAccessIterator end) {
        const auto length = distance(begin, end);
        
        if (length <= 0) return nullptr;
        
        auto mid = begin + length / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(begin, mid);
        root->right = sortedArrayToBST(mid+1, end);
        
        return root;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num.begin(), num.end());
    }
};