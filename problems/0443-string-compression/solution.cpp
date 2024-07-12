class Solution {
public:
    int compress(vector<char>& chars) {

        int count = 1, writeIdx = 0;

        for(int i = 1; i <= chars.size(); i++){
            if(i < chars.size() && chars[i] == chars[i-1]){
                count++; 
            } else {
                chars[writeIdx++] = chars[i-1];
                // Convert int to char (It may be multiple digits)
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[writeIdx++] = c;
                    }
                }
                count = 1;
            }
        }
        return writeIdx;
    }
};
