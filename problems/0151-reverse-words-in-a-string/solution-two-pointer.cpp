class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int index = 0;

        for(int start = 0; start < s.length(); ++start){
            if(s[start] != ' '){
                // if not the first word add a index 
                if(index != 0) s[index++] = ' ';

                int end = start;
                while(end < s.length() && s[end] != ' ') s[index++] = s[end++];
                reverse(s.begin() + index - (end - start), s.begin() + index);
                start = end;
            }
        }

        s.erase(s.begin() + index, s.end());
        
        return s;
    }
};
