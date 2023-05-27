//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

    void solve(int r, int c, int n, int m , vector<int>v, vector<vector<int>>&ans, vector<vector<int>>&grid){
        
        if(r < 0 || r > n-1 || c < 0 || c > m-1){
            return;
        }
        
        v.push_back(grid[r][c]);
        
        
        if(r == n-1 and c == m-1){
            
            ans.push_back(v);
            v.clear();
            return;    // backtrack
        }
        
        
        solve(r, c+1, n , m ,v, ans, grid);
        solve(r+1, c, n, m, v, ans, grid);
    }
    
    
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        
        vector<vector<int>>ans;
        vector<int>v;
        
        solve(0,0,n,m,v,ans,grid);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends