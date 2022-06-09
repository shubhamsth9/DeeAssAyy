// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    void recur(string str, int i, int k, string &res){
        if(i == str.length()-1 || k == 0){
            res = max(res, str);
            return;
        }
        for(int j=i+1; j<str.length(); j++){
            if(str[j] > str[i]){
                swap(str[i], str[j]);
                recur(str, i+1, k-1, res);
                swap(str[i], str[j]);
            }
        }
        recur(str, i+1, k, res);
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       string res = "";
       recur(str, 0, k, res);
       return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends