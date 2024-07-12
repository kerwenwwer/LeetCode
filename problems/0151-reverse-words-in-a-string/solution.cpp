class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result;
        

        while (ss >> word) {
            if (!result.empty()) {
                word += " ";
            }
            result = word + result;
        }
        
        return result;
    }
};
