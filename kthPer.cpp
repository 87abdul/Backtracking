//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
     void solve(int n, int cnt, vector<int>& ans, set<int>& s, vector<vector<int>>& v) {
        if (cnt == 0) {
            v.push_back(ans);
            return;
        }
    
        for (int i = 1; i <= n; ++i) {
            if (s.count(i) == 0) {
                ans.push_back(i);
                s.insert(i);
                solve(n, cnt - 1, ans, s, v);
                ans.pop_back();
                s.erase(s.find(i));
            }
        }
    
        return;
    }
    
    string kthPermutation(int n, int k) {
        vector<vector<int>> permutations;
        set<int> visited;
        vector<int> currentPermutation;
    
        solve(n, n, currentPermutation, visited, permutations);
    
        // If k is out of range, return an empty string
        if (k < 1 || k > permutations.size()) {
            return "";
        }
    
        // Get the kth permutation
        vector<int>& kthPermutation = permutations[k - 1];
    
        // Convert the permutation to a string
        string result = "";
        for (int i : kthPermutation) {
            result += to_string(i);
        }
    
        return result;
    }

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends