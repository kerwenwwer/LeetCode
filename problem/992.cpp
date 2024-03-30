class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return solution(nums, k) - solution(nums, k - 1);
    }

private:
    int solution(vector<int> &nums, int k)
    {
        int count = 0;
        int left = 0;

        unordered_map<int, int> map;
        for (int right = 0; right < nums.size(); right++)
        {
            if (map[nums[right]]++ == 0)
                k--;

            while (k < 0)
            {
                if (--map[nums[left]] == 0)
                    k++;
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }
};