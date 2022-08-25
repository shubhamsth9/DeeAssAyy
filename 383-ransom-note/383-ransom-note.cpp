class Solution {
public:
    bool canConstruct(string note, string mag) {
        int freq[26] = {0};
        for(char c:mag) freq[c-'a']++;
        for(char c:note){
            if(freq[c-'a'] == 0) return false;
            freq[c-'a']--;
        }
        return true;
    }
};