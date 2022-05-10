// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  //DP with tabulation approach
	int minDifference(int arr[], int n)  { 
	    int range=0;
	    for(int i=0;i<n;i++){
	        range += arr[i];
	    }
	    int sum = range/2;
	    bool t[n+1][sum+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(i==0) t[i][j]=false;
	            if(j==0) t[i][j]=true;
	        }
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1] <= j ){
	                t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
	            }
	            else
	                t[i][j] = t[i-1][j];
	        }
	    }
	    vector<int>v;
	    for(int j=0;j<=sum;j++){
	        if(t[n][j] == true){
	           v.push_back(j);
	        }
	    }
	    int minimumSum = INT_MAX;
	    for(int i=0;i<v.size();i++){
	        minimumSum = min(minimumSum, range-(2*v[i]));
	    }
	    return minimumSum;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends