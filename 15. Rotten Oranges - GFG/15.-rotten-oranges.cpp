// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        int res=0, total_oranges = 0, cnt = 0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] != 0) total_oranges++;
            }
        }
        
        int di[] = {1, -1, 0, 0};
        int dj[] = {0, 0, 1, -1};
        
        while(!q.empty()){
            int flag = 0;
            int n = q.size();
            cnt += n;
            
            for(int it=0; it<n; it++){
                auto tmp = q.front(); q.pop();
                
                for(int k = 0; k<4; k++){
                    int i = tmp.first + di[k];
                    int j = tmp.second + dj[k];
                    
                    if(i>=0 and i<grid.size() and j>=0 and j<grid[0].size() and grid[i][j] == 1){
                        grid[i][j] = 2;
                        q.push({i, j});
                        flag = 1;
                    }
                }
            }
            if(flag == 1) res++;
            else break;
        }
        
        if(total_oranges == cnt) return res;
        
        return -1;
        
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