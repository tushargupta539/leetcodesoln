class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // DP table
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: copy last row
        for (int j = 0; j < triangle[n-1].size(); j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        // Fill table bottom-up
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] +
                           min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};
