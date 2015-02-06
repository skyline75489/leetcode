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
    void traveral(TreeNode *root, int level, vector<vector<int>> &result, bool leftToRight) {
        if (root == nullptr) {
            return;
        }
        if (level > result.size()) {
            result.push_back(vector<int>());
        }
        if (leftToRight) {
            result[level-1].push_back(root->val);
        } else {
            result[level-1].insert(result[level-1].begin(), root->val);
        }
        
        traveral(root->left, level+1, result, !leftToRight);
        traveral(root->right, level+1, result, !leftToRight);
    }
    
    
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        traveral(root, 1, result, true);
        return result;
    }
};