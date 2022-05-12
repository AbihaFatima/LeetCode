// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    //Unbounded Knapsack
    //Approach - DP with tabulation
    
    long long int count(int coins[], int m, int n) {
        
        vector <vector<long long>> t(m+1, vector<long long>(n+1, 0));
        
        for(int i=0; i<=m; i++)
            t[i][0] = 1;
            
        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(coins[i-1]<=j){
                    t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends