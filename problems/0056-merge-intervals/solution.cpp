class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        if (intervals.size() == 1) return intervals;
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        /* 
         * Compare current interval to the last one of the ans.
         * If the overlap happens -> merge it.
         */ 
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++){
            vector<int>& last = ans.back();

            int current_start = intervals[i][0];

            if(current_start <= last[1]){
                // If [1,4],[2,3] -> last[1] > intervals[i][1] so take max();
                last[1] = max(last[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
