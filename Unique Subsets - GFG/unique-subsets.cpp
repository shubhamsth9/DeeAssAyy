// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    void util(int idx, int n, vector<int> temp, vector<int> &arr, vector<vector<int>>& res){
        res.push_back(temp);
        for(int i=idx; i<n; i++){
            temp.push_back(arr[i]);
            util(i+1, n, temp, arr, res);
            temp.pop_back();
            while(i < n-1 && arr[i+1] == arr[i]) i++;
        }
    }
    //Function to find all possible unique subsets.
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> res;
        vector<int> temp;
        sort(arr.begin(), arr.end());
        //set<vector<int>> st;
        util(0, n, temp, arr, res);
        
        // for(auto it:st){
        //     res.push_back(it);
        // }
        //sort(res.begin(), res.end());
        
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