//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:

    bool solve(int src, int k, vector<pair<int, int>> g[], vector<bool>& vis) {
        vis[src] = true;
        
        if (k <= 0) {
            return true;
        }
        
        for (auto adj : g[src]) {
            int u = adj.first;
            int wt = adj.second;
            
            if (vis[u]) {
                continue;
            }
            
            if (wt >= k) {
                return true;
            }
            
            if (solve(u, k - wt, g, vis)) {
                return true;
            }
        }
        
        vis[src] = false;
        return false;
    }
    
    
        bool pathMoreThanK(int V, int E, int k, int *a) {
        vector<pair<int, int>> g[V];
        
        // [a0, b0, w0, a1, b1, w1, a2, b2, w2, ...]

        for (int i = 0; i < E * 3; i += 3) {
            int u = a[i];
            int v = a[i + 1];
            int wt = a[i + 2];
            g[u].push_back({v, wt});
            g[v].push_back({u, wt});
        }
        
        vector<bool> vis(V, false);
        
        if (solve(0, k, g, vis)) {
            return 1;
        } else {
            return 0;
        }
    }

};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends