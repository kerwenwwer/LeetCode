class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> umap;
        
        for(int i = 0; i < n; i++){
            if(umap.count(s[i]) && umap[s[i]] > left){
                left = umap[s[i]];
            }
            umap[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};
