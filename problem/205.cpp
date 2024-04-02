class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.length(); ++i)
        {
            char from = s[i];
            char to = t[i];

            // Check the mapping from s to t
            if (sToT.find(from) != sToT.end())
            {
                if (sToT[from] != to)
                    return false;
            }
            else
            {
                sToT[from] = to;
            }

            // Check the mapping from t to s
            if (tToS.find(to) != tToS.end())
            {
                if (tToS[to] != from)
                    return false;
            }
            else
            {
                tToS[to] = from;
            }
        }

        return true;
    }
};