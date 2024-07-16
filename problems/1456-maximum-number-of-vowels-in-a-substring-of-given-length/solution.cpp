class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";

        int count = 0;

        for(int i = 0; i < k; i++){
            if(vowels.find(s[i]) != string::npos) count++;
        }

        int maxCount = count;

        for(int i = k; i < s.length(); i++){
            if(vowels.find(s[i - k]) != string::npos) count--;
            if(vowels.find(s[i]) != string::npos) count++;

            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};
