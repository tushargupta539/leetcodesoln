/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* prev=NULL;
    int minDiffInBST(TreeNode* root) {

        if(root==NULL)
        {
            return INT_MAX; 
        }
        int ans=INT_MAX;
        if(root->left!=NULL)
        {
            int leftnode=minDiffInBST( root->left);
            ans=min(ans,leftnode);
        }
        if(prev!=NULL)
        {
            ans= min(ans,root->val-prev->val);
        }
            prev=root;
        if(root->right!=NULL)
        {
           int rightnode=minDiffInBST( root->right);
           ans=min(ans,rightnode);
        }
        return ans;
    }
};