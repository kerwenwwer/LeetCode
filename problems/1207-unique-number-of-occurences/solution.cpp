class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        for(auto num : arr){
            countMap[num]++;
        }

        unordered_set<int> uniqueCounts;
        for(const auto&pair : countMap){
            if(!uniqueCounts.insert(pair.second).second) return false;
        }

        return true;
    }
};
