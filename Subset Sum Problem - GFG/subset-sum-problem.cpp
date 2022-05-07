// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    //Tabulation Method (DP)
    /*
        Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
        Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.
    */
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        bool t[n+1][sum+1];
        
        //Initialize 
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) t[i][j] = false; //When array is empty and sum is non zero
                if(j==0) t[i][j] = true; // when sum is 0 so here in this case empty subset is possible so we are returning true
            }
        }
        
        for(int i=1; i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                if(arr[i-1] <= j){ //The selected element is less than j
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                    //        when we choose it || when we leave it
                }
                else{   //When selected element greater than sum then we need to leave it;
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum]; //Return the last element of table.
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends