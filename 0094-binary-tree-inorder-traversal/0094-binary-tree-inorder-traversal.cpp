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
    vector<int> inorderTraversal(TreeNode* root) {
        //in order traversal using morris inorder approach
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                //inorder prederser
                TreeNode*ip=curr->left;
                while(ip->right!=NULL&&ip->right!=curr)
                {
                  ip=ip->right;
                }
                if(ip->right==NULL)//ab connection create karna hai
                {
                    ip->right=curr;
                    curr=curr->left;//yaha thread banayega 
                }
                else
                {
                    ip->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;                                    //yaha thread hatayenga
                }
            }
        }
        return ans;
    }
};