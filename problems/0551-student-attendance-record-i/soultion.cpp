class Solution {
public:
    bool checkRecord(string s) {
        int a_counter = 0;
        for(int i = 0; i < s.length(); i++){
            if(a_counter == 2) return false;
            if(s[i] == 'L'){
                if(s[i+1] == 'L' && s[i+2] == 'L') return false;
            } else if(s[i] == 'A'){
                a_counter++;
                if(a_counter == 2) return false;
            }
        }
        return true;
    }
};
