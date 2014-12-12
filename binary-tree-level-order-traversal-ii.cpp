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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        vector<int> curLevel; //当前层
        queue<TreeNode *> cur;
        queue<TreeNode *> next;
        
        cur.push(root);
        while (!cur.empty()) {
            while (!cur.empty()) {
                TreeNode *top = cur.front();
                cur.pop();
                if (top->left) {
                    next.push(top->left);
                }
                if (top->right) {
                    next.push(top->right);
                }
                curLevel.push_back(top->val);
            }
            result.push_back(curLevel);
            curLevel.clear();
            swap(cur, next); // 此时cur正好为空，next为下一层的节点
        }
        reverse(result.begin(), result.end());
        return result;
    }

};