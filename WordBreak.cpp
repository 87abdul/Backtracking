//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
         unordered_map<string, int>dp;

    int solve(string s, vector<string>& wordDict) {
        
        int n = s.length();
        
        // Base Case
        if(n == 0) return 1;
        
        
        if(dp[s] != 0) return dp[s];
        
        for(int i = 1 ; i <=n ; i++){
            
            int flag = 0;
            
            string ss = s.substr(0 , i);
            
            for(int j = 0 ; j < wordDict.size() ; j++){
                          
                if(ss.compare(wordDict[j]) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 1 and solve(s.substr(i , n - i) , wordDict) == 1)
                
                return dp[s] = 1;
        }
        
        return dp[s] = -1;
    }
    
    int wordBreak(string s, vector<string> &wordDict) {
        //code here
        
        int res = solve(s, wordDict);
        if(res == 1) return true;
        else return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends