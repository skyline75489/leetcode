/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 方法 1
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

// 方法 2
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode *p = root;
        vector<int> result;
        if (!p) {
            return result;
        }

        TreeNode *top, *last = NULL;
        stack<TreeNode *> q;
        while (p || !q.empty()) {
            if (p) {
                q.push(p);
                p = p->left;
            } else {
                top = q.top();
                if (top->right == NULL || top->right == last) {
                    q.pop();
                    result.push_back(top->val);
                    last = top;
                } else {
                    p = top->right;
                }
            }
        }

        return result;
    }
};