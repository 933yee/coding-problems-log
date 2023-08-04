class Solution {
   public:
    void dfs(TreeNode* root, int& cnt, int k, int& ans) {
        if (root == NULL) return;
        dfs(root->left, cnt, k, ans);
        cnt += 1;
        if (cnt == k) ans = root->val;
        dfs(root->right, cnt, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans;
        dfs(root, cnt, k, ans);
        return ans;
    }
};