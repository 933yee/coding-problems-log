class Solution {
   public:
    bool checkSame(TreeNode* root, TreeNode* subRoot) {
        if (!root) return !subRoot;
        if (!subRoot) return !root;
        if (root->val == subRoot->val) {
            return checkSame(root->left, subRoot->left) && checkSame(root->right, subRoot->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;
        if (checkSame(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};