class Solution {
   public:
    int dfs(TreeNode* root, int mx) {
        if (root == NULL) return 0;
        mx = max(mx, root->val);
        return (root->val >= mx) + dfs(root->left, mx) + dfs(root->right, mx);
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};