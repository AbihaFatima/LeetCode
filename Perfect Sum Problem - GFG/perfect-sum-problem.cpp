// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	//DP with tabulation
	int perfectSum(int arr[], int n, int sum)
	{
        int t[n+1][sum+1];
        long long mod=1e9+7;
        
        // base condition 
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){//j started from zero to handle extra zeroes at end and special testcase
            //(only here we are starting j from 0 as some testcase were not passing in GFG)
                if(arr[i-1] <= j){
                    t[i][j] = (t[i-1][j]%mod + t[i-1][j-arr[i-1]]%mod)%mod;
                }
                else
                    t[i][j] = t[i-1][j]%mod;
            }
        }
        return t[n][sum];
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends