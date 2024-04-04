class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        vector<int> &small = (nums1.size() > nums2.size()) ? nums1 : nums2;
        vector<int> &large = (nums1.size() > nums2.size()) ? nums2 : nums1;

        for (int i = 0; i < small.size(); i++)
        {
            if (find(large.begin(), large.end(), small[i]) != large.end() &&
                find(ans.begin(), ans.end(), small[i]) == ans.end())
            {
                ans.push_back(small[i]);
            }
        }
        return ans;
    }
};