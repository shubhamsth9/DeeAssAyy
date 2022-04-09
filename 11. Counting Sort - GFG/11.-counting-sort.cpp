// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string str){
        
        int hash[26] = {0};
        int n = str.length();
        
        for(int i=0; i<n; i++){
            hash[str[i] - 'a']++;
        }
        
        string res;
        
        for(int i=0; i<26; i++){
            while(hash[i] > 0){
                res.push_back(i+'a');
                hash[i] -= 1;
            }
        }
        
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}
  // } Driver Code Ends