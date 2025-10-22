class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0||i==n-1||j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        vis[i][j]=true;
                    }
                }
            }
        }
        while(q.size()>0)
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r-1>=0&&grid[r-1][c]==1&&!vis[r-1][c])//top
            {
                q.push({r-1,c});
                vis[r-1][c]=true;
            }
             if(r+1<n&&grid[r+1][c]==1&&!vis[r+1][c])//)//down
            {
                q.push({r+1,c});
                vis[r+1][c]=true;
            }
             if(c-1>=0&&grid[r][c-1]==1&&!vis[r][c-1])//)//left
            {
                q.push({r,c-1});
                vis[r][c-1]=true;
            }
             if(c+1<m&&grid[r][c+1]==1&&!vis[r][c+1])//)//right
            {
                q.push({r,c+1});
                vis[r][c+1]=true;
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&!vis[i][j])
                {
                    count++;
                }
            }
        }
        
    return count;

        
    }
};