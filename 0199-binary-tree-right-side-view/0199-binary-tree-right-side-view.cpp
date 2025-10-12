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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        q.push(root);
        while(q.size()>0)
        {  int n=q.size();
            for(int i=0;i<n;i++)
           {
            TreeNode*currnode=q.front();
            q.pop();
            if(i==n-1)
            {
                ans.push_back(currnode->val);
            }
            if(currnode->left!=NULL)
            {
                q.push(currnode->left);
            }
            if(currnode->right!=NULL)
            {
                q.push(currnode->right);
            }
            
        }
        }
    
    return ans;
    }
};