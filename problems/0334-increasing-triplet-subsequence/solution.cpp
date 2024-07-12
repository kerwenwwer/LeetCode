class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f_small = INT_MAX, s_small = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= f_small){
                f_small = nums[i];
            } else if (nums[i] <= s_small){
                s_small = nums[i];
            } else {
                return true;
            }
        }

        return false;
    }
};	
