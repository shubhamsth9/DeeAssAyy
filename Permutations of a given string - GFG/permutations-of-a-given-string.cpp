// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    
	    void util(int idx, string s, vector<string>& res, set<string>& st){
	        if(idx == s.length()-1){
	            if(st.find(s) == st.end()){
	                st.insert(s);
	                res.push_back(s);
	            }
	            return;
	        }
	        for(int i=idx; i<s.length(); i++){
	            if(s[idx] != s[i] || i == idx){
    	            swap(s[idx], s[i]);
    	            util(idx+1, s, res, st);
    	            swap(s[idx], s[i]);
	            }
	        }
	    }
	    
		vector<string>find_permutation(string s)
		{
    	    set<string> st;
		    vector<string> res;
		    util(0, s, res, st);
		    sort(res.begin(), res.end());
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends