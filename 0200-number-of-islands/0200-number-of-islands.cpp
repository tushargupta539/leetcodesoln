class Solution {
public:
void dfs(int i,int j,int n,int m,vector<vector<bool>>&vis,vector<vector<char>>&grid)
{
    if(i<0||j<0||i>=n||j>=m||grid[i][j]!='1'||vis[i][j])
    {
        return;
    }///using dfs function for the recursive call
    vis[i][j]=true;
    dfs(i-1,j,n,m,vis,grid);//top;
    dfs(i+1,j,n,m,vis,grid);//down
    dfs(i,j+1,n,m,vis,grid);//right
    dfs(i,j-1,n,m,vis,grid);//left
}
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&&!vis[i][j])
                {
                    dfs(i,j,n,m,vis,grid);
                    count++;
                }
            }
        }
        return count;

    }
};