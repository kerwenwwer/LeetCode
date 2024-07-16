class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;

        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        double avgS = sum;

        for(int i = k; i < nums.size(); i++){
            sum = sum - nums[i - k] + nums[i];
            avgS = max((double)sum, avgS);
        }
        
        return avgS / k;
    }
};
