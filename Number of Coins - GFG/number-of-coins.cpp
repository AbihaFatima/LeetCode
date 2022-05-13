// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
    //Approach - DP(tabulation method)
	int minCoins(int coins[], int M, int V) 
	{ 
	    //M is size of coin array and V is the sum/amount
	    int t[M+1][V+1];
	    
	    //Initialization of first row and first col
        for(int i=0;i<=M;i++){
            for(int j=0;j<=V;j++){
                if(i==0) t[i][j]=INT_MAX-1;
                if(j==0) t[i][j]=0;
            }
        }
        
        //Initialization of first row and first col
        for(int i=1;i<=M;i++){
            for(int j=1;j<=V;j++){
                if(j%coins[i-1]==0){
                    t[i][j] = j/coins[i-1];
                }
                else{
                    t[i][j] = -1;
                    
                }
            }
        }
            
        for(int i=1;i<=M;i++){
            for(int j=1;j<=V;j++){
                if(coins[i-1] <= j){
                    t[i][j] = min(1+t[i][j-coins[i-1]], t[i-1][j]);
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return (t[M][V] == INT_MAX || t[M][V] == INT_MAX-1) ? -1 : t[M][V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends