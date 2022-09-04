class Solution {
public:
    bool checkDistances(string s, vector<int>& dist) {
        
        int n = s.size();
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(s[i] == s[j] && j-i-1 != dist[s[i]-'a'])
                    return false;
        return true;
    }
};