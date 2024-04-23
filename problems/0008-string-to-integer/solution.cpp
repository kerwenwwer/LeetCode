class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int sign = 1;

        long result = 0;

        // Handle space
        while (i < s.length() && s[i] == ' ')
            i++;

        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        while (i < s.length() && isdigit(s[i]))
        {
            result = result * 10 + s[i] - '0';

            // Handle overflow
            if (sign == 1 && result > INT_MAX)
                return INT_MAX;
            if (sign == -1 && (-1 * result) < INT_MIN)
                return INT_MIN;
            i++;
        }
        return result * sign;
    }

private:
    bool isdigit(char c)
    {
        if (c >= '0' && c <= '9')
            return true;
        else
            return false;
    }
};