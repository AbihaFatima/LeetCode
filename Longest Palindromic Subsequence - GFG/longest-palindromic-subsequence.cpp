// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    int LCS(string s, string b, vector<vector<int>>&dp,int m,int n){
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
    
  public:
    int longestPalinSubseq(string s) {
        string b = s;
        reverse(b.begin(),b.end());
        int m = s.size();
        int n = m;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans = LCS(s,b,dp,m,n);
        return ans;
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends