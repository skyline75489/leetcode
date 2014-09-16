/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 用栈模拟
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode *p = root;
        vector<int> result;
        if (!p) {
            return result;
        }
        
        stack<TreeNode *> q;
        while (p || !q.empty()) {
            while (p) {
                result.push_back(p->val);
                q.push(p);
                p = p->left;
            }
            if (!q.empty()) {
                p = q.top();
                q.pop();
                p = p->right;
            }
        }
        return result;
    }
};