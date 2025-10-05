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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;  ///weare using level order traversal which is also known as bfs
        q.push({root,0});
        long long maxwidth=0;
        while(q.size()>0)
        {   long long stind=q.front().second;
            long long endindx=q.back().second;
            long long currqsize=q.size();
            maxwidth=max(maxwidth,(endindx-stind+1));
            for(int i=0;i<currqsize;i++)
            {
              auto currnode=q.front();
              q.pop();
              long long index = currnode.second - stind; 
              if(currnode.first->left!=NULL)
              {
                q.push({currnode.first->left,2*index+1});
              }
              if(currnode.first->right!=NULL)
              {
                q.push({currnode.first->right,2*index+2});
              }
            }
        }
         return maxwidth;
        
    }
};