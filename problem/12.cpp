class Solution
{
public:
    string intToRoman(int num)
    {
        // Define pairs of Roman numerals and their values
        vector<pair<int, string>> romanNumerals = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string result = "";
        // Iterate over the Roman numeral/value pairs
        for (auto &pair : romanNumerals)
        {
            // Find how many times the Roman numeral fits into num
            int count = num / pair.first;
            num %= pair.first;
            // Append the Roman numeral count times
            while (count--)
            {
                result += pair.second;
            }
        }
        return result;
    }
};