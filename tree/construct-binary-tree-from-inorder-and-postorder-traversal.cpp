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
    TreeNode *constructTree2(InputIterator pStart, InputIterator pEnd, InputIterator iStart, InputIterator iEnd) {
        if (pStart == pEnd) {
            return nullptr;
        }
        if (iStart == iEnd) {
            return nullptr;
        }
        
        auto rootVal = *prev(pEnd);
        auto root = new TreeNode(rootVal);
        auto rootIndex = find(iStart, iEnd, rootVal);
        auto leftLength = distance(iStart, rootIndex);
        
        root->left = constructTree2(pStart, next(pStart, leftLength), iStart, next(iStart, leftLength));
        root->right = constructTree2(next(pStart, leftLength), prev(pEnd), next(rootIndex), iEnd);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return constructTree2(begin(postorder), end(postorder), begin(inorder), end(inorder));
    }
};