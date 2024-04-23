class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_global = INT_MIN;
        int temp = 1;

        // left -> right
        for(int i = 0; i < nums.size(); i++){
            temp *= nums[i];
            max_global = max(temp, max_global);
            if(temp == 0) temp = 1;
        }
        
        temp = 1;
        
        // right -> left
        for(int i = nums.size() - 1; i >= 0; i--){
            temp *= nums[i];
            max_global = max(temp, max_global);
            if(temp == 0) temp = 1;
        }

        return max_global;
    }
};
