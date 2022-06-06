// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool util(const pair<int, int> &a, const pair<int, int> &b){
        return (a.second < b.second);
    }
class Solution
{
    public:
    
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({start[i], end[i]});
        }
        sort(vec.begin(), vec.end(), util);
        
        int cnt = 1;
        pair<int, int> temp = vec[0];
        int i = 1;
        while(i < n){
            if(vec[i].first > temp.second){
                cnt++;
                temp = vec[i];
            }
            i++;
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends