class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, end = 0;
        int zero_count = 0;
        int max_length = 0;
        
        while (end < nums.size()) {
            if (nums[end] == 0) {
                zero_count++;
            }
            
            while (zero_count > 1) {
                if (nums[start] == 0) {
                    zero_count--;
                }
                start++;
            }

            max_length = max(max_length, end - start);
            
            end++;
        }
        
        return max_length;
    }
};
