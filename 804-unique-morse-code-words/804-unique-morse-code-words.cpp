class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> ref = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> uset;
        
        for(auto s:words){
            string temp;
            for(int i=0; i<s.size(); i++){
                temp += ref[s[i]-'a'];
            }
            uset.insert(temp);
        }
        return uset.size();
    }
};