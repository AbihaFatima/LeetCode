class Solution {
    int lcs(string &str1, string &str2,int m,int n, vector<vector<int>> &dp){
        if(m==0 || n==0) return 0;
        if (str1[m - 1] == str2[n - 1])
            return dp[m][n] = 1 + lcs(str1, str2, m - 1, n - 1, dp);
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        return dp[m][n] = max(lcs(str1, str2, m, n - 1, dp),
                              lcs(str1, str2, m - 1, n, dp));
    }
public:
    int minDistance(string str1, string str2) {
	    int m = str1.length();
	    int n = str2.length();
	    vector<vector<int>> dp(m+1,vector<int>(n+1, -1));
	    int LCS = lcs(str1,str2,m,n,dp);
        /*
        example : str1: sea
                  str2: eat   => LCS: ea
                  so 's' should be deleted and 't' should be inserted to make it 'eat'
                  i.e 1 deletion and 1 insertion
                  so # of deletion = length of word1 - length of LCS
                     # of insertion = length of word2- length of LCS
        */
        return (m-LCS)+(n-LCS);
    }
};