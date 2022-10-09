class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
            map<int, int> M;
            bool F = false;
            function<void(TreeNode *)> DFS = [&](TreeNode *cur) {
                if (cur == nullptr) return;
                if (M[k - cur->val] > 0) {
                        F = true;
                        ++M[k - cur->val];
                        return;
                }
                ++M[cur->val];
                if (cur->left) DFS(cur->left);
                if (cur->right) DFS(cur->right);
            };
            DFS(root);
            return F;
    }
};