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
    vector<vector<int>> result;
    vector<int> cur;
    
    bool isLeaf(TreeNode *node) {
        return !node->left && !node->right;
    }

    void pathSum(TreeNode* root, int gap, vector<int> &cur, vector<vector<int>> &result){
        if (!root) {
            return;
        }
        cur.push_back(root->val);
        if (isLeaf(root) && root->val == gap) {
            result.push_back(cur);
        }
        pathSum(root->left, gap-root->val, cur, result);
        pathSum(root->right, gap-root->val,cur , result);
        
        cur.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        vector<int> cur;
        if (!root) {
            return result;
        }
        pathSum(root, sum, cur, result);
        return result;
    }
};