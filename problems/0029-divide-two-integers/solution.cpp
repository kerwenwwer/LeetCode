class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool isPositive = (dividend < 0 == divisor < 0);

        long long num = abs((long long)dividend);
        long long den = abs((long long)divisor);
        long long result = 0;

        while (num >= den)
        {
            long long temp = den, multiple = 1;
            while (num >= (temp << 1))
            {
                temp <<= 1;
                multiple <<= 1;
            }
            num -= temp;
            result += multiple;
        }

        if (result == (1 << 31) && isPositive)
            return INT_MAX;

        return isPositive ? result : -result;
    }
};