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
    bool isValidBST(TreeNode *root) {
        TreeNode *p = root;
        vector<int> result;
        if (!p) {
            return true;
        }
        if (!p->left && !p->right) {
            return true;
        }
        int prev, cur;
        prev = cur = INT_MIN;
        stack<TreeNode *> q;
        while (p || !q.empty()) {
            while (p) {
                q.push(p);
                p = p->left;
            }
            if (!q.empty()) {
                p = q.top();
                cur = p->val;
                if (result.size() > 0 && cur <= prev) {
                    return false;
                }
                result.push_back(p->val);
                prev = cur;
                q.pop();
                p = p->right;
            }
        }
        return true;
    }
};