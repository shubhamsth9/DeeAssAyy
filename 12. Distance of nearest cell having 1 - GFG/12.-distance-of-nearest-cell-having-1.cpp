// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>> res(n, vector<int>(m, INT_MAX));
	    queue<pair<int, int>> q;
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j] == 1){
	                res[i][j] = 0;
	                q.push({i, j});
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        auto temp = q.front();
	        int i=temp.first, j=temp.second, val = res[i][j]+1;
	        q.pop();
	        
	        if(i-1 >= 0 && val<res[i-1][j]){
	            res[i-1][j] = val;
	            q.push({i-1, j});
	        }
	        if(j-1 >= 0 && val<res[i][j-1]){
	            res[i][j-1] = val;
	            q.push({i, j-1});
	        }
	        if(i+1 < n && val<res[i+1][j]){
	            res[i+1][j] = val;
	            q.push({i+1, j});
	        }
	        if(j+1 < m && val<res[i][j+1]){
	            res[i][j+1] = val;
	            q.push({i, j+1});
	        }
	    }
	    
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends