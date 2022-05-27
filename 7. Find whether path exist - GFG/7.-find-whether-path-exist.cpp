// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    bool dfs(int i, int j, int n, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= n) return false;
        if(grid[i][j] == 2) return true;
        if(grid[i][j] == 0) return false;
        if(grid[i][j] == 3) grid[i][j] = 0;
        
        bool temp = dfs(i+1, j, n, grid) || dfs(i, j+1, n, grid) || dfs(i-1, j, n, grid) || dfs(i, j-1, n, grid);
        
        grid[i][j] = 3;
        
        return temp;
    }
    
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int x, y;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    x = i, y = j;
            }
        }
        
        return dfs(x, y, n, grid);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends