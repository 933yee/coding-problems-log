class Solution {
   public:
    int ans = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        ans = max(ans, L + R + 1);
        return max(L, R) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return max(dfs(root), ans) - 1;
    }
};