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
    template <typename InputIterator>
    TreeNode *constructTree(InputIterator pStart, InputIterator pEnd, InputIterator iStart, InputIterator iEnd) {
        if (pStart == pEnd) {
            return nullptr;
        }
        if (iStart == iEnd) {
            return nullptr;
        }
        
        auto root = new TreeNode(*pStart);
        auto rootIndex = find(iStart, iEnd, *pStart);
        auto leftLength = distance(iStart, rootIndex);
        
        root->left = constructTree(next(pStart), next(pStart, leftLength+1), iStart, next(iStart, leftLength));
        root->right = constructTree(next(pStart, leftLength+1), pEnd, next(rootIndex), iEnd);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return constructTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
    }
};