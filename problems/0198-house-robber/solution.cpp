class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        // DP table
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        
        if(n == 1) return nums[0];

        //Initial status
        dp[0][0] = 0;
        dp[0][1] = nums[0]; 
        
        //Interate
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};
