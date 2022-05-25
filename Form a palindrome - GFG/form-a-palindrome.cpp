// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    int lcs(string s, string b, int m, int n,vector<vector<int>>&dp){
            for(int i=0;i<m+1;i++){
                for(int j=0;j<n+1;j++){
                    if(i==0||j==0) dp[i][j]=0;
                }
            }
            for(int i=1;i<m+1;i++){
                for(int j=1;j<n+1;j++){
                    if(s[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            return dp[m][n];
        }
  public:
    int countMin(string s){
        string b = s;
        reverse(b.begin(),b.end());
        int m = s.size();
        int n=m;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int LCS = lcs(s,b,m,n,dp);
        int ans = (m-LCS);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends