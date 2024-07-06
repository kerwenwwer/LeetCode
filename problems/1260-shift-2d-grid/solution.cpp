class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Normalize k
        k = k % total;
        
        vector<vector<int>> ans(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int tmp = (i * n + j + k) % total;
                int newRow = tmp / n;
                int newCol = tmp % n;
                ans[newRow][newCol] = grid[i][j];
            } 
        }

        return ans;
    }
};
