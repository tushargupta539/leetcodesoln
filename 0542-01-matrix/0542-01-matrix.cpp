class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>> q;


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                     dis[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }
        while(q.size()>0)
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int val=q.front().second;
            q.pop();
            if(row-1>=0&&dis[row-1][col]==-1)//top
            {
                dis[row-1][col]=dis[row][col]+1;
                q.push({{row-1,col},val+1});
            }
             if(row+1<n&&dis[row+1][col]==-1)//bottom
            {
                dis[row+1][col]=dis[row][col]+1;
                q.push({{row+1,col},val+1});
            }
             if(col-1>=0&&dis[row][col-1]==-1)
            {
                dis[row][col-1]=dis[row][col]+1;
                q.push({{row,col-1},val+1});
            }
             if(col+1<m &&dis[row][col+1]==-1)
            {
                dis[row][col+1]=dis[row][col]+1;
                q.push({{row,col+1},val+1});
            }
        }
        return dis;
    }
};