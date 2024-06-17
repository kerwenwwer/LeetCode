class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        // 基本情況：當 nums 只有一個元素時，返回這個單元素的排列
        if (nums.size() == 1) {
            vector<int> singleList;
            singleList.push_back(nums[0]);
            res.push_back(singleList);
            return res;
        }

        // 遍歷 nums 中的每個元素
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];  // 選擇第 i 個元素 n
            vector<int> remainingNums;
            
            // 創建一個新的數組，不包括第 i 個元素 n
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    remainingNums.push_back(nums[j]);
                }
            }
            
            // 對剩下的數組進行遞歸排列
            vector<vector<int>> perms = permute(remainingNums);
            
            // 將選中的元素 n 插入到每個排列的開頭，並添加到結果集中
            for (vector<int> p : perms) {
                p.insert(p.begin(), n);  // 在排列的開頭插入 n
                res.push_back(p);  // 將修改後的排列添加到結果集中
            }
        }
        
        return res;    
    }
};

