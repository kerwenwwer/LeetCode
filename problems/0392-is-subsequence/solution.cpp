class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPtr = 0;  
        int tPtr = 0; 
        
        while (sPtr < s.length() && tPtr < t.length()) {
            if (s[sPtr] == t[tPtr]) {
                sPtr++; 
            }
            tPtr++;  
        }
    
        return sPtr == s.length();
    }
};
