class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target);
    }

private:
    int binarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid; // Target found
            }

            // Determine which side is sorted
            if (arr[left] <= arr[mid]) { // Left side is sorted
                if (arr[left] <= target && target < arr[mid]) {
                    right = mid - 1; // Target is in the left half
                } else {
                    left = mid + 1; // Target is in the right half
                }
            } else { // Right side is sorted
                if (arr[mid] < target && target <= arr[right]) {
                    left = mid + 1; // Target is in the right half
                } else {
                    right = mid - 1; // Target is in the left half
                }
            }
        }

        return -1; // Target not found
    }
};
