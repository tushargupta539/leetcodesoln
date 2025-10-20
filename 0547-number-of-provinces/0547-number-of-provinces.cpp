class Solution {
public:
vector<vector<int>> convertToAdjList(vector<vector<int>>& isconnected) {
    int n = isconnected.size();
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isconnected[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    return adj;
}

void dfshelper(vector<vector<int>>&l,int u,int par,vector<bool>&vis)
{
     vis[u]=true;
     for(auto v:l[u])
     {
        if(!vis[v])
        {
            dfshelper(l,v,u,vis);
        }
     }
}
    int findCircleNum(vector<vector<int>>& isconnected) {
        int count =0;
        int n=isconnected.size();
        vector<bool>vis(n,false);
        vector<vector<int>> l = convertToAdjList(isconnected);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {   count++;
                dfshelper(l,i,-1,vis);
            }
        }
       return count; 
    }
};