int dfs(TreeNode *root, int sum);
int dfs(TreeNode *root, int sum) {
    if (!root) {
        return 0;
    }
    if (isLeaf(root)) {
        return sum * 10 + root->val;
    }
    return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);
}

int sumNumbers(TreeNode *root) {
    return dfs(root, 0);
}
