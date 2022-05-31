// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        int res=0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()){
            int flag = 0;
            int n = q.size();
            
            for(int it=0; it<n; it++){
                auto tmp = q.front(); q.pop();
                int i = tmp.first, j = tmp.second;
                
                if(i-1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                    flag = 1;
                }
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                    flag = 1;
                }
                if(i+1 < grid.size() && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                    flag = 1;
                }
                if(j+1 < grid[0].size() && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                    flag = 1;
                }
            }
            if(flag == 1) res++;
            else break;
        }
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    res = -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends