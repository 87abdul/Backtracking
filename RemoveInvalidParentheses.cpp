//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
  vector<string>res;
  
  unordered_map<string, int>mp;
  
    int getMinInvalid(string s){
        
        stack<char>st;
        
        int i = 0 ;
        
        while( i < s.size()){
            
            if(s[i] == '('){
                st.push(s[i]);
            }
            
            else if(s[i] == ')'){
                
                if(st.size() > 0 and st.top() == '(')
                    st.pop();
                else 
                    st.push(s[i]);
            }
            i++;
        }
        
        return st.size();
    }
    
    void solve(string s, int Minval){
        
        if(mp[s] != 0) return ;
        
        else
                mp[s]++;
                
        
        if(Minval < 0) return ; 
        
        if(Minval == 0){
            
            if(!getMinInvalid(s))
                res.push_back(s);
                return ;
        }
        
        for(int i = 0 ; i< s.size() ;i++){
            
            string left = s.substr(0 , i);
            string right = s.substr(i+1);
            solve(left + right , Minval-1);
        }
        
        return ;
    }
    
    
    vector<string> removeInvalidParentheses(string s) {
        // code here
        
        solve(s, getMinInvalid(s));
        
        sort(res.begin(), res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends