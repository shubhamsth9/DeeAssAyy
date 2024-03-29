class Solution {
public:
    bool canConstruct(string note, string mag) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int freq[26] = {0};
        for(int i=0; i<mag.size(); i++) freq[mag[i]-'a']++;
        for(int i=0; i<note.size(); i++){
            if(freq[note[i]-'a'] == 0) return false;
            freq[note[i]-'a']--;
        }
        return true;
    }
};