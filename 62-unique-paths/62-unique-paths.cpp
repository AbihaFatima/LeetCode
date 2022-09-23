class Solution {
public:
    //DP Memoization
    int countPaths(int i,int j,int m, int n,vector<vector<int>> &dp){
        if(i==m-1 && j==n-1) return dp[i][j]=1;
        else if(i>=m || j>=n) return dp[i][j]=0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        else
            return dp[i][j] = countPaths(i+1,j,m,n,dp) + countPaths(i,j+1,m,n,dp);
    }
    
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        int num = countPaths(0,0,m,n,dp);
        //if(m==1 && n==1) return num;
        //else
            return num;
        
    }
    // //DP Approach (top-down - tabulation)
    // int uniquePaths(int m, int n) {
    //     int dp[m][n];
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==0 || j==0){
    //                 dp[i][j] = 1;
    //             }
    //             else{
    //                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }
};