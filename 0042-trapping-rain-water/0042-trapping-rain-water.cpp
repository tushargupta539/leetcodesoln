class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left_max_i(n);
        vector<int> right_max_i(n);

        left_max_i[0] = height[0];
        right_max_i[n-1] = height[n-1];

        for(int i = 1; i < n; i++) {
            left_max_i[i] = max(height[i], left_max_i[i-1]);
        }

        for(int i = n-2; i >= 0; i--) {
            right_max_i[i] = max(height[i], right_max_i[i+1]);
        }

        int sum = 0;

        for(int i = 0; i < n; i++) {
            int water = min(left_max_i[i], right_max_i[i]) - height[i];
            sum += water;
        }

        return sum;
    }
};