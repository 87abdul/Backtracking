//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	/*The permu() function is called recursively for each index from 0 to N-1.
	At each level of recursion, a loop is executed N-index times. 
	Therefore, the total number of function calls is N * (N-1) * (N-2) * ... * 1 = N!.
    Inside the permu() function, swap() function is called twice for each index,
    so the total number of swap() function calls is also N!.
    Inserting a string into a set takes O(log N) time on average. 
    Since we are inserting N! strings into the set, 
    the total time complexity of the set insertions is O(N! * log N!).
    Finally, we are copying the contents of the set to a vector using the assign() function,
    which takes O(N) time.*/
   void permu(int i,string S,set<string> &ans)
    {
        if(i>=S.size())
        {
            ans.insert(S);
            return;
        }
        for(int index=i;index<S.size();index++)
        {
            swap(S[index],S[i]);
            permu(i+1,S,ans);
            swap(S[index],S[i]);
        }
    
    }
    
 vector<string>find_permutation(string S)
 {
     set<string> ans;

     vector<string> result;
     permu(0,S,ans);
     
     
     result.assign(ans.begin(),ans.end());
     sort(result.begin(),result.end());
     return result;
 }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends