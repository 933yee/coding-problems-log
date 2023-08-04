class Solution {
   public:
    pair<bool, int> dfs(TreeNode* root) {
        if (!root) return {true, 0};

        auto pL = dfs(root->left);
        if (!pL.first) return {false, 0};
        auto pR = dfs(root->right);
        if (!pR.first) return {false, 0};
        return {(abs(pL.second - pR.second) <= 1), (max(pL.second, pR.second) + 1)};
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};