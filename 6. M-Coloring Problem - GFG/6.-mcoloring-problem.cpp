// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isValid(int node, int col, int n, vector<int>& color, bool graph[101][101]){
    for(int i=0; i<n; i++){
        if(i != node && graph[node][i] && col == color[i])
            return false;
    }
    return true;
}

bool util(int node, int m, int n, vector<int>& color, bool graph[101][101]){
    if(node == n) return true;
    
    for(int i=1; i<=m; i++){
        if(isValid(node, i, n, color, graph)){
            color[node] = i;
            if(util(node+1, m, n, color, graph)) return true;
            color[node] = -1;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, -1);
    return util(0, m, n, color, graph);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends