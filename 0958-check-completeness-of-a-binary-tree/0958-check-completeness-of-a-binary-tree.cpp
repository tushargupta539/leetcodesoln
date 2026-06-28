class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        bool seenNull = false;

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                seenNull = true;
            }
            else {

                if (seenNull)
                    return false;

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};