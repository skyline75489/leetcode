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
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        TreeNode *p = root;
        if (!p->left && !p->right)
            return 1;
        else {
            return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
        }
    }

    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }
        TreeNode *p = root;
        int ldepth = maxDepth(p->left);
        int rdepth = maxDepth(p->right);
        
        if (abs(ldepth - rdepth) > 1) {
            return false;
        }
        return isBalanced(p->left) && isBalanced(p->right);
    }
};