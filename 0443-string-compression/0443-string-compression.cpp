class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> s;
        int cnt = 1;
        int i;
        for(i = 1; i<chars.size(); i++){
            if(chars[i] == chars[i-1]){
                cnt++;
            }
            else{
                s.push_back(chars[i-1]);
                if(cnt > 1){
                    if(cnt > 9){
                        string tmp = to_string(cnt);
                        for(auto ch:tmp){
                            s.push_back(ch);
                        }
                    }
                    else
                        s.push_back(cnt + '0');
                }
                cnt = 1;
            }
        }
        s.push_back(chars[i-1]);
        if(cnt > 1){
            if(cnt > 9){
                string tmp = to_string(cnt);
                for(auto ch:tmp){
                    s.push_back(ch);
                }
            }
            else
                s.push_back(cnt + '0');
        }
        chars = s;
        return chars.size();
    }
};