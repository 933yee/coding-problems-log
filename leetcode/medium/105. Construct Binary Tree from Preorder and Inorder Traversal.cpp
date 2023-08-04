class Solution {
   public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& idx, int l, int r) {
        if (l > r) return NULL;
        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        int m;
        for (int i = l; i <= r; i++) {
            if (inorder[i] == val) {
                m = i;
                break;
            }
        }
        root->left = build(preorder, inorder, idx, l, m - 1);
        root->right = build(preorder, inorder, idx, m + 1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(preorder, inorder, idx, 0, preorder.size() - 1);
    }
};