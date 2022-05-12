// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  //Unbounded Knapsack - standard problem
  //DP with tabulation
  
    int cutRod(int price[], int N) {
        int t[N+1][N+1];
        int length[N];
        for(int i=0;i<N;i++){
           length[i]=i+1;
        }
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                if (i == 0 || j == 0)
                    t[i][j] = 0;
                else if(length[i-1] <= j){
                    t[i][j] = max(price[i-1] + t[i][j-length[i-1]], t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[N][N];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends