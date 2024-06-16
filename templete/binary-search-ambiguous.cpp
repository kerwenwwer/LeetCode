int binarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = int(arr.size()) - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        
        // left is the insertion point
        return left;
    }
