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
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        
        if (nullptr == root->left) {
            return;
        }
        TreeNode *p = root->left;
        while (p->right) {
            p = p->right;
        }
        p->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
};