class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Find the leftmost position of target
        int left = binarySearchL(nums, target);
        // If the target is not found, return [-1, -1]
        if (left == nums.size() || nums[left] != target) {
            return {-1, -1};
        }

        int right = binarySearchR(nums, target);
        return {left, right};
    }
private:
    int binarySearchL(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }

    int binarySearchR(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left - 1;
    }
};
