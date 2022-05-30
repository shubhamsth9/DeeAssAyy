// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    void dfs(int i, int j, int& cnt, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(grid[i][j] == 0) return;
        grid[i][j] = 0;
        cnt++;
        
        dfs(i-1, j, cnt, grid);
        dfs(i-1, j-1, cnt, grid);
        dfs(i, j-1, cnt, grid);
        dfs(i+1, j-1, cnt, grid);
        dfs(i+1, j, cnt, grid);
        dfs(i+1, j+1, cnt, grid);
        dfs(i, j+1, cnt, grid);
        dfs(i-1, j+1, cnt, grid);
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    dfs(i, j, cnt, grid);
                    res = max(res, cnt);
                }
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends