class Solution {
public:
    int minSquares(int n,int dp[]){
        if(n<=3) return n;
        int ans = n;
        if(dp[n]!= -1) return dp[n];
        for(int i=1;i*i<=n;i++){
            ans = min(ans, 1+minSquares(n-(i*i),dp));
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return minSquares(n,dp);
    }
};