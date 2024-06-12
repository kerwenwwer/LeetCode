class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        auto helper = [&](int start, int end){
            vector<int> dp(end - start + 1, 0);
            dp[0] = nums[start];
            dp[1] = max(nums[start], nums[start + 1]);
            for(int i = 2; i < end - start + 1; i++){
                dp[i] = max(dp[i-1], dp[i-2] + nums[start+i]);
            }
            return dp[end - start];
        };

        return max(helper(0, n - 2), helper(1, n - 1));
    }
};
