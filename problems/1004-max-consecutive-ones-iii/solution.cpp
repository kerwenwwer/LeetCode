class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxCount = 0;

        while(right < nums.size()){
            if(nums[right] == 0){
                zeroCount++;
            }

            while(zeroCount > k){
                if(nums[left] == 0) zeroCount--;
                left++;
            }

            maxCount = max(maxCount, right - left + 1);

            right++;
        }

        return maxCount;
    }
};
