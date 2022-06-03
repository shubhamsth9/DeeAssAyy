// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    
    bool valid(int x, int y, int n){
        if(x < 0 || y < 0 || x >= n || y >= n) return false;
        return true;
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int tar_x =TargetPos[0]-1, tar_y=TargetPos[1]-1;
	    
	    vector<vector<bool>> vis(N, vector<bool>(N, false));
	    queue<pair<int, int>> q;
	    q.push({KnightPos[0]-1, KnightPos[1]-1});
	    vis[KnightPos[0]-1][KnightPos[1]-1] = true;
	    
	    int cnt = 0;
	    int dx[] = {-2, 2}, dy[] = {-1, 1};
	    
	    while(!q.empty()){
	        
	        int n = q.size();
	        while(n--){
	            auto temp = q.front(); q.pop();
	            int curr_x = temp.first, curr_y = temp.second;
    	        if(curr_x == tar_x && curr_y == tar_y) return cnt;
    	        
    	        for(int i=0; i<2; i++){
    	            for(int j=0; j<2; j++){
    	                int new_x = curr_x + dx[i], new_y = curr_y + dy[j];
    	                if(valid(new_x, new_y, N) && !vis[new_x][new_y]){
    	                    vis[new_x][new_y] = true;
    	                    q.push({new_x, new_y});
    	                }
    	                new_x = curr_x + dy[j], new_y = curr_y + dx[i];
    	                if(valid(new_x, new_y, N) && !vis[new_x][new_y]){
    	                    vis[new_x][new_y] = true;
    	                    q.push({new_x, new_y});
    	                }
    	            }
    	        }
	        }
	        cnt++;
	    }
	    return cnt;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends