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
int height(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftheight=height( root->left);
   int rightheight= height( root->right);
   return max(leftheight,rightheight)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
     if(root==NULL)
     {
        return 0;
     }
     int left=diameterOfBinaryTree( root->left);
     int right=diameterOfBinaryTree( root->right);
     int currdia=height(root->left)+height(root->right);
     return max(max(left,right),currdia);
        
    }
};