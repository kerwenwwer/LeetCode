class Solution
{
public:
    int calculate(string s)
    {
        if (s.empty())
            return 0;

        stack<int> st;
        int currentNumber = 0;
        char operation = '+';

        for (int i = 0; i < s.length(); i++)
        {
            char currentChar = s[i];

            // Check if it is a digit and form the number
            if (isdigit(currentChar))
            {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }

            // If the current character is not a digit and not a space, or it is the last character, do the calculation
            if (!isdigit(currentChar) && !isspace(currentChar) || i == s.length() - 1)
            {
                if (operation == '+')
                {
                    st.push(currentNumber);
                }
                else if (operation == '-')
                {
                    st.push(-currentNumber);
                }
                else if (operation == '*' || operation == '/')
                {
                    int stackTop = st.top();
                    st.pop();
                    if (operation == '*')
                    {
                        st.push(stackTop * currentNumber);
                    }
                    else
                    {
                        st.push(stackTop / currentNumber);
                    }
                }
                // Update operation to the current character
                operation = currentChar;
                // Reset current number
                currentNumber = 0;
            }
        }

        int result = 0;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }
};