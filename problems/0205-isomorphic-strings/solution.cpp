class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> sTt;
        unordered_map<char, char> tTs;

        for (int i = 0; i < s.length(); i++)
        {
            char a = s[i];
            char b = t[i];

            if (sTt.find(a) != sTt.end())
            {
                if (sTt[a] != b)
                    return false;
            }
            else
            {
                sTt[a] = b;
            }

            if (tTs.find(b) != tTs.end())
            {
                if (tTs[b] != a)
                    return false;
            }
            else
            {
                tTs[b] = a;
            }
        }
        return true;
    }
};