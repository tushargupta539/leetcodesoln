class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //the crux is the same we need to use the dijkstra      agorithm but here we use the ways for the same purspose for explanation refre to the striver sheets
        //now we need to create the graph as it is one based index graph 
        vector<pair<int,int>>adj[n];
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dis(n,1e18);
        vector<int>ways(n,0);
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0});//dist,node
        long long mod=(int)(1e9+7);
        while(pq.size()>0)
        {
            auto it=pq.top();
            long long dist=it.first;
            int node=it.second;
            pq.pop();
            if (dist > dis[node]) continue; 
            for(auto iter:adj[node])
            {
                int adjnode=iter.first;
                long long edwt=iter.second;
                //this the first time we are arriving this 
                if(dist+edwt<dis[adjnode])
                {
                     dis[adjnode]=dist+edwt;
                     pq.push({dis[adjnode],adjnode});
                     ways[adjnode]=ways[node];
                }
                else if(dist+edwt==dis[adjnode])
                {
                    ways[adjnode]=(ways[node]+ways[adjnode])%mod;
                }

            }
        }
        return ways[n-1]%mod;
    }
};