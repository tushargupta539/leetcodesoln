class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>>mp;
        mp[1]={1};
        for(auto i=1;i<stones.size();i++)
        {
            if(mp.find(stones[i])==mp.end())
            continue;
            for(auto jump:mp[stones[i]])
            {
                mp[stones[i]+jump].insert(jump);
                mp[stones[i]+jump+1].insert(jump+1);
                mp[stones[i]+jump-1].insert(jump-1);
            }
        }
        return mp[stones.back()].size()!=0;
        
    }
};