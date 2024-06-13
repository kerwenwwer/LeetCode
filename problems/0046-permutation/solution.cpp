class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> path;
        vector<bool> used(nums.size(), false);
        
        backtrack(nums, path, used, ans);

        return ans;
    }

private:
    /* 
        backtrack() -> dfs with backtracking
        nums: Input array with all elements.
        path: Current permutation canditate.
        used: Array size = nums.size(), mark the element that has been used in "nums".
        ans: Output format. 
    */ 
    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used, vector<vector<int>>& ans){
        // Return condition -> size of path = size of nums (means we find a permutation).
        if(nums.size() == path.size()){
            ans.push_back(path);
        }


        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, path, used, ans);
            used[i] = false;
            path.pop_back();
        }
    }
};
