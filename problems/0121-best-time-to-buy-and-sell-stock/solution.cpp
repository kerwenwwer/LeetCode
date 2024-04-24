class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = INT_MAX;
        int profit = 0;
        for (auto &i : prices)
        {
            if (i < min)
            {
                min = i;
            }
            int calprofit = i - min;
            if (calprofit > profit)
            {
                profit = calprofit;
            }
        }
        return profit;
    }
};