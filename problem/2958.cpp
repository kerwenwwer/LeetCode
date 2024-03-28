#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int maxLength = 0;
        int left = 0;

        unordered_map<int, int> temp;

        for (int right = 0; right < nums.size(); right++)
        {
            temp[nums[right]]++; // Update current element's freq.

            if (temp[nums[right]] > k)
            {
                while (nums[left] != nums[right])
                {
                    temp[nums[left]]--;
                    left++;
                }
                temp[nums[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
