class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int res=0;
        int oddcount=0;
        mp[oddcount]=1;
        for(int i=0;i<n;i++)
        {
            oddcount+=(nums[i]%2);
            if(mp.count(oddcount-k))
            {
                res+=mp[oddcount-k];
            }
            mp[oddcount]++;
        }
             return res;
    }
};