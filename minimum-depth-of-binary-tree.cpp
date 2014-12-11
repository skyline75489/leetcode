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
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        TreeNode *p = root;
        if (!p->left && !p->right)
            return 1;
        else {
            return std::min(root->left==NULL?INT_MAX:minDepth(root->left), root->right == NULL?INT_MAX:minDepth(root->right)) + 1;
        }
    }
};