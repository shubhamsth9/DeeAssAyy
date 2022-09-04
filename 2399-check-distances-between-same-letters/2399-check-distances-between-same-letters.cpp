class Solution {
public:
    bool checkDistances(string s, vector<int>& dist) {
        int n = s.size();
        vector<int> v(26, -1);
        for(int i=0; i<n; i++){
            if(v[s[i]-'a'] == -1) v[s[i]-'a'] = i;
            else if(i-v[s[i]-'a']-1 != dist[s[i]-'a']) return false;
        }
        return true;
    }
};