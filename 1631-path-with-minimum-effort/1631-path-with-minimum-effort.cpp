class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        //we are using the dijktra algo to solve tis ques
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};
       while(pq.size()>0)
       {
        auto it=pq.top();
        pq.pop();
        int diff=it.first;
        int row=it.second.first;
        int col=it.second.second;
        if(row==n-1&&col==m-1)return diff;
        for(int i=0;i<4;i++)
        {
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m)//valid check karne ke liya hai
            {
                int effort=max(abs(heights[nrow][ncol]-heights[row][col]),diff);
                if(effort<dis[nrow][ncol])
                {  dis[nrow][ncol]=effort;
                    pq.push({effort,{nrow,ncol}});
                }
            }
        }
       }
        return 0;//as it is unreachable 
    }
};