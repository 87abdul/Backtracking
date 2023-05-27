//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
int n, m;
    int ans = -1;
    // D, R, U, L
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

public:
    bool isvalid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void dfs(int i, int j, int dest_i, int dest_j, int len, vector<vector<int>> &matrix)
    {
        if (!isvalid(i, j))
            return;

        if (i == dest_i && j == dest_j)
        {
            ans = max(ans, len);
            return;
        }
        
        matrix[i][j] = 0;
        for (int idx = 0; idx < 4; idx++)
        {
            int x = i + dx[idx];
            int y = j + dy[idx];
            if (isvalid(x, y))
                if (matrix[x][y] == 1)
                    dfs(x, y, dest_i, dest_j, len + 1, matrix);
        }
        matrix[i][j] = 1;
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        n = matrix.size();
        m = matrix[0].size();
        if (matrix[xs][ys])
            dfs(xs, ys, xd, yd, 0, matrix);
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
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends