/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getPath(TreeNode *root, vector<int> cur, vector<vector<int>> &r) {
        if (!root) {
            return;
        }
        
        cur.push_back(root->val);
        
        if (!root->left && !root->right) {
            r.push_back(cur);
        }
        getPath(root->left, cur, r);
        getPath(root->right, cur, r);
        
        cur.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<vector<int>> r;
        vector<int> cur;
        
        if (!root) {
            return result;
        }
        getPath(root, cur, r);
        for (size_t i = 0; i < r.size(); i++) {
            vector<int> v = r[i];
            stringstream ss;
            for (size_t j = 0; j < v.size(); j++) {
                if (j != 0) {
                    ss << "->";
                }
                ss << v[j];
            }
            string s = ss.str();
            result.push_back(s);
        }
        return result;
    }

};
