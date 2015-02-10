/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 这个方法太帅了!!
// 来自 https://oj.leetcode.com/discuss/21995/a-very-concise-solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        
        if (root == nullptr) {
            return result;
        }
        s.push(root);
        
        TreeNode *p = nullptr;
        while (!s.empty()) {
            p = s.top();
            s.pop();
            result.insert(result.begin(), p->val);
            if (p->left) {
                s.push(p->left);
            }
            if (p->right) {
                s.push(p->right);
            }
        }
        return result;
    }
};