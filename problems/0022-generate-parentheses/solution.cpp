class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

private:
    void backtrack(vector<string> &ans, string current,
                   int open, int close, int n)
    {
        // We use all char,
        // ex. n = 3 so we could use 3 "(" and 3 ")" that is 6.
        if (current.length() == n * 2)
        {
            ans.push_back(current);
            return;
        }

        // if we still have "(", so that mean's open is less than n
        if (open < n)
        {
            backtrack(ans, current + "(", open + 1, close, n);
        }

        // if we still have ")" since that close is one to one with open so
        if (close < open)
        {
            backtrack(ans, current + ")", open, close + 1, n);
        }
    }
};