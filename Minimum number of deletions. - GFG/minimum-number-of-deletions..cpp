// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends

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
    
int minDeletions(string s, int m) { 
        string b = s;
        reverse(b.begin(),b.end());
        int n=m;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int LCS = lcs(s,b,m,n,dp);
        int ans = (m-LCS);
        return ans;
} 