class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ret;
        if (root == NULL)
            return ret;

        q.push(root);
        while (!q.empty()) {
            ret.push_back(q.front()->val);

            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->right != NULL)
                    q.push(cur->right);
                if (cur->left != NULL)
                    q.push(cur->left);
            }
        }
        return ret;
    }
};