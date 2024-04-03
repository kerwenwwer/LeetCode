class Solution
{
public:
    bool dfs(vector<vector<char>> &board, string word, int wordIndex, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (board[i][j] != word[wordIndex])
            return false;

        // If the last character matches, we've found the word
        if (wordIndex == word.size() - 1)
        {
            return true;
        }

        // Mark the cell as visited by changing its value (to avoid revisiting)
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all possible directions
        bool found = dfs(board, word, wordIndex + 1, i + 1, j) ||
                     dfs(board, word, wordIndex + 1, i - 1, j) ||
                     dfs(board, word, wordIndex + 1, i, j + 1) ||
                     dfs(board, word, wordIndex + 1, i, j - 1);

        // Restore the cell's original value after exploring
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};