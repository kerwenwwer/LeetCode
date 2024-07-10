class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> prefix(gain.size() + 1, 0);

        for(int i = 1; i <= gain.size(); i++){
            prefix[i] = prefix[i-1] + gain[i-1];
        }

        sort(prefix.begin(), prefix.end());
        
        return prefix[prefix.size() - 1];
    }
};
