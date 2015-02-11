/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// 与层序遍历的思路类似
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        vector<TreeLinkNode *> curLevel; //当前层
        queue<TreeLinkNode *> cur;
        queue<TreeLinkNode *> next;
        
        cur.push(root);
        while (!cur.empty()) {
            while (!cur.empty()) {
                TreeLinkNode *top = cur.front();
                if (top == nullptr) {
                    return;
                }
                cur.pop();
                next.push(top->left);
                next.push(top->right);
                
                curLevel.push_back(top);
            }
            curLevel.push_back(nullptr);
            auto i = curLevel.begin();
            for ( ;i != prev(curLevel.end()); i++) {
                TreeLinkNode *curNode = *i;
                TreeLinkNode *nextNode = *(i+1);
                curNode->next = nextNode;
            }
            curLevel.clear();
            swap(cur, next);
        }
    }
};