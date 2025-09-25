class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //trial for githubcommit
        int n=nums.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(st.size()>0&&nums[st.top()]<=nums[i%n])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[i%n]=-1;
                st.push(i%n);
            }
            else
            {
                ans[i%n]=nums[st.top()];
                st.push(i%n);
            }
        }
        return ans;
    }
};