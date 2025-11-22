class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //first of all wew need to form the graph for the same
        vector<vector<int>>adj(numCourses);
        for(auto &it :prerequisites)
        {
             int course=it[0];
             int precourse=it[1];
             
             adj[precourse].push_back(course);
        }
        //now we make the graph now we can apply the topological sort on the ques for the same
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;

            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(q.size()>0)
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
            
        }
        if(topo.size()==numCourses)
        {
            return true;
        }
        return false;
    }
};