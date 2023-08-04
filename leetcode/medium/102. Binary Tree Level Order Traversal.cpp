class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        if (root == NULL) return ret;

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ret.push_back(v);
        }
        return ret;
    }
};