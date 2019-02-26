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

    void traversal(TreeNode *root, int level, vector<vector<int>> &result) {
        if (!root) {
            return;
        }
        // 保证每一层只有一个vector
        if (level > result.size()) {
            result.push_back(vector<int>());
        }
        result[level-1].push_back(root->val);
        traversal(root->left, level+1, result);
        traversal(root->right, level+1, result);
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        traversal(root, 1, result);
        return result;
    }

};