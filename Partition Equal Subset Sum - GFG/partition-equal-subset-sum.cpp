// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int equalPartition(int N, int nums[])
    {
        int sum = 0;
        bool ans;
        for(int i=0;i<N;i++){
            sum += nums[i];
        }
        
        if(sum%2 != 0) 
            return 0;
            
        int t[N+1][sum/2+1];
        
        //initialization
        for(int i=0;i<=N;i++){
            for(int j=0;j<=sum/2;j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum/2;j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[N][sum/2];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends