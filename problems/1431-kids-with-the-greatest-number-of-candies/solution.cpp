class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);

        // Find the max number in candies
        int max_number = INT_MIN;
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] > max_number){
                max_number = candies[i];
            }
        }

        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= max_number){
                result[i] = true;
            }
        }

        return result;
    }
};
