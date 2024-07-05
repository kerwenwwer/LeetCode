class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        for(int i = 0, j = m; i < n; i++){
            nums1[j] = nums2[i];
            j++;
        }
        sort(nums1.begin(), nums1.end());
    }
};s
