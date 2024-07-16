class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        int left = 0, right = nums.size() - 1;

        sort(nums.begin(), nums.end());

        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum == k){
                count++;
                left++;
                right--;
            } else if(sum < k){
                left++;
            } else {
                right--;
            }
        }
        
        return count;
    }
};
