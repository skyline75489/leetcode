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
    bool isLeaf(TreeNode *node) {
        return !node->left && !node->right;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }
        if (root->val == sum && isLeaf(root)) {
            return true;
        }
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};