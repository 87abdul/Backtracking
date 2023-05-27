// #include<bits/stdc++.h>
 
// using namespace std;
 
 // Backtracking
 
// int solve(int row,int col,set<pair<int,int>>&st,vector<vector<bool>> visited,int i,int j,int cnt)
// {
//     if(i==row || i<0 || j<0 || j==col || st.count({i,j}) || visited[i][j])
//         return INT_MAX;
 
//     if(j==col-1)
//         return cnt;
 
//     visited[i][j]=true;    
//     int l1=solve(row,col,st,visited,i+1,j,cnt+1);
//     int l2=solve(row,col,st,visited,i-1,j,cnt+1);
//     int l3=solve(row,col,st,visited,i,j+1,cnt+1);
//     int l4=solve(row,col,st,visited,i,j-1,cnt+1);
//     visited[i][j]=false;
 
//     return min({l1,l2,l3,l4});
// }
 
// int main()
// {
//    int row,col;
//    cin>>row>>col;
//    vector<vector<int>> mat(row,vector<int>(col));
//    vector<vector<bool>> visited(row,vector<bool>(col,false));
//    for(int i=0;i<row;++i)
//    {
//        for(int j=0;j<col;++j)
//        {
//            cin>>mat[i][j];
//        }
//    }
 
//    set<pair<int,int>> st;
//    for(int i=0;i<row;++i)
//    {
//        for(int j=0;j<col;++j)
//        {
//            if(mat[i][j]==0)
//            {
//                pair<int,int> p{i,j};
//                st.insert(p);
 
//                 if(i+1<row)
//                 {
//                     pair<int,int> p{i+1,j};
//                     st.insert(p);
//                 }
 
//                 if(i-1>=0)
//                 {
//                     pair<int,int> p{i-1,j};
//                     st.insert(p);
//                 }
 
//                 if(j+1<col)
//                 {
//                     pair<int,int> p{i,j+1};
//                     st.insert(p);
//                 }
 
//                 if(j-1>=0)
//                 {
//                     pair<int,int> p{i,j-1};
//                     st.insert(p);
//                 }
//            }
//        }
//    }
 
//    int ans=INT_MAX;
//    for(int i=0;i<row;++i)
//    {
//        if(st.count({i,0})==0){
//            int length=solve(row,col,st,visited,i,0,0);
//            cout<<i<<" "<<length<<endl;
//            ans=min(ans,length);
//        }
//    }
 
//    cout<<ans;
 
//    return 0;
// }



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

    // Multi-source BFS
    
// 	int findShortestPath(vector<vector<int>> &mat)
//     {
//         int n=mat.size(),m=mat[0].size(),d[4]={1,-1,0,0};
//         for(int i=0;i<n;i++)
//             for(int j=0;j<m;j++)
//                 if(!mat[i][j]){
//                     for(int k=0;k<4;k++){
//                         int x= i+d[k], y= j+d[3-k];
//                         if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1)
//                             mat[x][y]=2;
//                     }
//                 }
//         queue<pair<int,int> >q;
//         for(int i=0;i<n;i++)
//             if(mat[i][0]==1)
//                 mat[i][0]=2,q.push({i,0});
//         int ans=1;
//         while(!q.empty()){
//             int s=q.size(),i,j;
//             while(s--){
//                 tie(i,j) = q.front();
//                 q.pop();
//                 if(j==m-1)
//                     return ans;
//                 for(int k=0;k<4;k++){
//                     int x= i+d[k], y= j+d[3-k];
//                     if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1)
//                         mat[x][y]=2,q.push({x,y});
//                 }
//             }
//             ans++;
//         }
//         return -1;
//     }
 
   // DP
   
   int ans=INT_MAX;
   bool is_valid(vector<vector<int>> mat, int i, int j, int col, int row)
   {
      
          if (j + 1 < col)
       {
           if (mat[i][j + 1]==0)
               return false;
       }
       if (i + 1 < row)
       {
           if (mat[i + 1][j]==0)
               return false;
       }
       if (j - 1 >= 0)
       {
           if (mat[i][j - 1]==0)
               return false;
       }
       if (i - 1 >= 0)
       {
           if (mat[i - 1][j]==0)
               return false;
       }
       return true;
   
   }
   void find_sortestpath(vector<vector<int>> mat, int i, int j, int step, int col, int row,
   vector<vector<int>>&dp)
   {
         
       if (i < 0 || i >= row)
           return;
       if (j < 0  || j >= col)
           return;
      
       if (!mat[i][j] || mat[i][j]==-1)
           return;
       if(dp[i][j]<step) return ;
           dp[i][j]=step;
       if (!is_valid(mat, i, j, col, row))
           return;
       if (j == col - 1){
           ans = min(ans, step);
           return ;
       }
      
       mat[i][j] = -1;
       find_sortestpath(mat, i - 1, j, step + 1, col, row,dp);
       find_sortestpath(mat, i+1 , j, step + 1, col, row,dp);
       find_sortestpath(mat, i, j + 1, step + 1, col, row,dp);
       
   }
  
   int solve(vector<vector<int>> &mat, int row, int col)
   {
   vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
       for (int i = 0; i < row; i++)
       {
           if (is_valid(mat, i, 0,col,row))
           {
                find_sortestpath(mat, i, 0, 1, col, row,dp);
           }
       }
       return ans;
   }
   int findShortestPath(vector<vector<int>> &mat)
   {
       int row = mat.size();
       int col = mat[0].size();
      
       solve(mat, row, col);
       if (ans == INT_MAX)
           return -1;
       return ans;
   }

//     int solve(int row,int col,set<pair<int,int>>&st,vector<vector<bool>> visited,int i,int j,int cnt)
//     {
//         if(i==row || i<0 || j<0 || j==col || st.count({i,j}) || visited[i][j])
//             return INT_MAX;
     
//         if(j==col-1)
//             return cnt;
     
//         visited[i][j]=true;    
//         int l1=solve(row,col,st,visited,i+1,j,cnt+1);
//         int l2=solve(row,col,st,visited,i-1,j,cnt+1);
//         int l3=solve(row,col,st,visited,i,j+1,cnt+1);
//         int l4=solve(row,col,st,visited,i,j-1,cnt+1);
//         visited[i][j]=false;
     
//         return min({l1,l2,l3,l4});
//     }
    
//     int findShortestPath(vector<vector<int>> &mat)
//     {
//       // code here
      
//       int row = mat.size();
//       int col = mat[0].size();
      
//     // vector<vector<int>> mat(row,vector<int>(col));
//   vector<vector<bool>> visited(row,vector<bool>(col,false));
//     //   set<pair<int,int>> st;
//     //   int ans=INT_MAX;

//       set<pair<int,int>> st;
//   for(int i=0;i<row;++i)
//   {
//       for(int j=0;j<col;++j)
//       {
//           if(mat[i][j]==0)
//           {
//               pair<int,int> p{i,j};
//               st.insert(p);
 
//                 if(i+1<row)
//                 {
//                     pair<int,int> p{i+1,j};
//                     st.insert(p);
//                 }
 
//                 if(i-1>=0)
//                 {
//                     pair<int,int> p{i-1,j};
//                     st.insert(p);
//                 }
 
//                 if(j+1<col)
//                 {
//                     pair<int,int> p{i,j+1};
//                     st.insert(p);
//                 }
 
//                 if(j-1>=0)
//                 {
//                     pair<int,int> p{i,j-1};
//                     st.insert(p);
//                 }
//           }
//       }
//   }
 
//   int ans=INT_MAX;
//   for(int i=0;i<row;++i)
//   {
//       if(st.count({i,0})==0){
//           int length=solve(row,col,st,visited,i,0,0);
//           ans=min(ans,length);
//       }
//   }
   
//   return ans;
 

//     }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends