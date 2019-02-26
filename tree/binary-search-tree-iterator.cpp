/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<int> treeStack;
    BSTIterator(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        constructStack(root);
    }
    
    void constructStack(TreeNode *p) {
        if (p->right) {
            constructStack(p->right);
        }
        treeStack.push(p->val);
        if (p->left) {
            constructStack(p->left);
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !treeStack.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        int top = treeStack.top();
        treeStack.pop();
        return top;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */