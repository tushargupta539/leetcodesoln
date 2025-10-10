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
TreeNode* helper(vector<int>&preorder,int &i,int &upperbound)
{
    if(i>=preorder.size()||preorder[i]>upperbound)
    {
        return NULL;
    }
    
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=helper(preorder,i,root->val);
        root->right=helper(preorder,i,upperbound);
    
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int upperbound=INT_MAX;
       return helper(preorder,i,upperbound);
        
    }
};