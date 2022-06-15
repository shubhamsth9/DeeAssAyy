// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    void util(int idx, int n, vector<int> temp, vector<int> &arr, set<vector<int>>& st){
        if(idx == n){
            st.insert(temp);
            return;
        }
        util(idx+1, n, temp, arr, st);
        temp.push_back(arr[idx]);
        util(idx+1, n, temp, arr, st);
    }
    //Function to find all possible unique subsets.
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> res;
        vector<int> temp;
        sort(arr.begin(), arr.end());
        set<vector<int>> st;
        util(0, n, temp, arr, st);
        
        for(auto it:st){
            res.push_back(it);
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends