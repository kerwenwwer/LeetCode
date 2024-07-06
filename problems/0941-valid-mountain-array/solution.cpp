class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int top = 0, valley = 0;

        int max_val = INT_MIN, ids = -1;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > max_val){
                max_val = arr[i];
                ids = i;
            }
        }

        if(arr[0] == max_val || arr[arr.size() - 1] == max_val) return false;

        for(int i = 0; i < ids; i++){
            if(arr[i] >= arr[i+1]) return false;
        }

        for(int i = ids; i < arr.size() - 1; i++){
            if(arr[i] <= arr[i+1]) return false;
        }

        return true;
    }
};
