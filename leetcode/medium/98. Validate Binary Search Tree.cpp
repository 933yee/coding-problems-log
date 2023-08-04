class Solution {
   public:
    bool dfs(TreeNode* root, long& prev) {
        if (root == NULL) return true;

        if (!dfs(root->left, prev))
            return false;

        if (prev < root->val)
            prev = root->val;
        else
            return false;

        if (!dfs(root->right, prev))
            return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return dfs(root, prev);
    }
};