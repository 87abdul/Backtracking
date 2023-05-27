//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int row, int col, vector<vector<int>>&mat, int n, vector<string>&ans, string move , vector<vector<int>>&vis){
        
        // Base Case
        if(row == n-1 and col == n-1){
            ans.push_back(move);
            return ;
        }
        
        
        // Downward 
        
        if(row+1 < n and !vis[row+1][col] and mat[row+1][col] == 1){
                        vis[row][col] = 1;
            solve(row+1, col, mat, n, ans, move + 'D' , vis);
                        vis[row][col] = 0;

        }

        // Leftward 
        
        if(col-1 >=0  and !vis[row][col-1] and mat[row][col-1] == 1){
                        vis[row][col] = 1;
            solve(row, col-1, mat, n, ans, move + 'L' , vis);
                        vis[row][col] = 0;
            
        }
        // Rightward 
        
        if(col+1 < n and !vis[row][col+1] and mat[row][col+1] == 1){
                        vis[row][col] = 1;
            solve(row, col+1, mat, n, ans, move + 'R' , vis);
                        vis[row][col] = 0;

        }
        
        // Upward 
        
        if(row-1 >=0  and !vis[row-1][col] and mat[row-1][col] == 1){
                        vis[row][col] = 1;
            solve(row-1, col, mat, n, ans, move + 'U' , vis);
                        vis[row][col] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        // Your code goes here
        
        vector<string>ans;
        
        vector<vector<int>>vis(n, vector<int>(n,0));
        if(mat[0][0] == 1)
            solve(0,0,mat,n, ans, "" , vis);
            
            return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends