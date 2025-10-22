class Solution {
public:
void dfs(int i,int j,vector<vector<char>>&ans,vector<vector<char>>&board,vector<vector<bool>>&vis)
{  int n = board.size(), m = board[0].size();
    vis[i][j]=true;
    if(i>0 && !vis[i-1][j]&&board[i-1][j]=='O')
    {
        dfs(i-1,j,ans,board,vis);//top

    }
     if(i<n-1 &&!vis[i+1][j]&&board[i+1][j]=='O')
    {
        dfs(i+1,j,ans,board,vis);//bottom

    }
     if(j>0&&!vis[i][j-1]&&board[i][j-1]=='O')
    {
        dfs(i,j-1,ans,board,vis);//left

    }
     if(j<m-1 &&!vis[i][j+1]&&board[i][j+1]=='O')
    {
        dfs(i,j+1,ans,board,vis);//right

    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        //we are going to use dfs for this ques
        vector<vector<char>>ans=board;
        for(int j=0;j<m;j++)//for first and last row
        {
            if(!vis[0][j]&&board[0][j]=='O')//first row 
            {
                  dfs(0,j,ans,board,vis);
            }
            if(!vis[n-1][j]&&board[n-1][j]=='O')//last row
            {
                dfs(n-1,j,ans,board,vis);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0]&&board[i][0]=='O')//first coloumn
            {
                dfs(i,0,ans,board,vis);
            }
            if((!vis[i][m-1]&&board[i][m-1]=='O'))//last column
            {
                dfs(i,m-1,ans,board,vis);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    board[i][j]='X';
                }
            
            }
        }
    }
};