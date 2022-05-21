// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    int lcs(string X, string Y, int m, int n,
            vector<vector<int> >& dp)
    {
        if (m == 0 || n == 0)
            return 0;
        if (X[m - 1] == Y[n - 1])
            return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
     
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
                              lcs(X, Y, m - 1, n, dp));
    }
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return m+n-lcs(X,Y,m,n,dp);
        
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends