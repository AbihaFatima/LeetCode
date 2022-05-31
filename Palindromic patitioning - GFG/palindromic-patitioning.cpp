// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int t[501][501];
    
    bool isPalindrome(string &str,int i,int j){
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &str,int i,int j){
        
        if(i>=j) return t[i][j]=0; //base condition(invalid input)
        
        if(t[i][j]!=-1) return t[i][j];
        
        if(isPalindrome(str,i,j)==true){
            t[i][j]=0;
            return t[i][j];
        }
        int minimum = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp = 1 + solve(str,i,k) + solve(str,k+1,j);
            if(temp<minimum){
                minimum = temp;
            }
        }
        return t[i][j]=minimum;
    }
public:
    int palindromicPartition(string str)
    {
        memset(t,-1,sizeof(t));
        int n = str.size();
        return solve(str,0,n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends