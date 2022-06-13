// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends

bool isValid(int i, int j, int n, vector<int> maze[]){
    if(i >= n || j >= n) return false;
    return true;
}

bool util(int i, int j, int n, vector<vector<int>>& vis, vector<int> maze[]){
    
    if(i == n-1 && j == n-1){
        vis[i][j] = 1;
        return true;
    }
    
    for(int step = 1; step <= maze[i][j]; step++){
        if(isValid(i, j+step, n, maze)){
            if(util(i, j+step, n, vis, maze)){
                vis[i][j] = 1;
                return true;
            }
        }
        if(isValid(i+step, j, n, maze)){
            if(util(i+step, j, n, vis, maze)){
                vis[i][j] = 1;
                return true;
            }
        }
    }
    return false;
}

void solve(int n, vector<int> maze[]) 
{
    vector<vector<int>> vis(n, vector<int>(n, 0));
    
    if(maze[0][0] == 0){
        cout<<"-1"<<endl;
        return;
    }
    
    if(util(0, 0, n, vis, maze) == false) cout<<"-1"<<endl;
        
    else {
        for(int i=0; i<n; i++){
            for(int j= 0; j<n; j++) cout<<vis[i][j]<<" ";
            cout<<endl;
        }
    }
    
    return;
}