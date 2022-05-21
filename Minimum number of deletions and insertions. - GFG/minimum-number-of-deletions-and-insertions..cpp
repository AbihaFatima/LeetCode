// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		
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
	int minOperations(string str1, string str2) 
	{
	    int m = str1.length();
	    int n = str2.length();
	    vector<vector<int>> dp(m+1,vector<int>(n+1, -1));
	    int LCS = lcs(str1,str2,m,n,dp);
	    
	    return (n-LCS)+(m-LCS);
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends