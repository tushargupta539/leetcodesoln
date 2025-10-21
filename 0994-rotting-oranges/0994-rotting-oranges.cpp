class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
        int ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;//isme i,j ka pair and time store karegay aur is ques me hume bfs traversal use karena hai 


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        //sari vale ko pop karena hai kyoki yeh bfs traverasaal hai is liya jo ab tak padehai wahi karena hai 
        while(q.size()>0)
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            q.pop();
            ans=max(ans,time);
            if(i-1>=0&&grid[i-1][j]==1&&!vis[i-1][j])//top
            {
             q.push({{i-1,j},time+1});  
             vis[i-1][j]=true;
            }
            if(i+1<n&&grid[i+1][j]==1&&!vis[i+1][j])//bottom
            {
                 q.push({{i+1,j},time+1});  
                 vis[i+1][j]=true;
            }
            if(j-1>=0&&grid[i][j-1]==1&&!vis[i][j-1])//left
            {
                 
                 q.push({{i,j-1},time+1}); 
                 vis[i][j-1]=true; 
                 
            }
            if(j+1<m&&grid[i][j+1]==1&&!vis[i][j+1])//right
            {
                    q.push({{i,j+1},time+1});  
                    vis[i][j+1]=true;
            }
        

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&!vis[i][j])
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};