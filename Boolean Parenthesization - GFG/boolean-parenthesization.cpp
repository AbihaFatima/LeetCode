// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //❌Recursive approach - TLE
    // int solve(string &s, int i,int j, bool isTrue){
    //     if(i>j) return 0;
    //     if(i==j){
    //         if(isTrue==true) return s[i]=='T';
    //         else return s[i]=='F';
    //     }
    //     int ans=0;
    //     for(int k=i+1;k<j;k+=2){
    //         int left_T = solve(s,i,k-1,true);
    //         int left_F = solve(s,i,k-1,false);
    //         int right_T = solve(s,k+1,j,true);
    //         int right_F = solve(s,k+1,j,false);
    //         if(s[k]=='&'){
    //             if(isTrue==true){
    //                 ans += left_T*right_T; 
    //             }
    //             else{
    //                 ans += left_T*right_F + right_T*left_F + left_F*right_F;
    //             }
    //         }
    //         else if(s[k]=='|'){
    //             if(isTrue==true){
    //                 ans += left_T*right_F + left_T*right_T + left_F*right_T;
    //             }
    //             else{
    //                 ans += left_F*right_F;
    //             }
    //         }
    //         else if(s[k]=='^'){
    //             if(isTrue==true){
    //                 ans += left_T*right_F + right_T*left_F;
    //             }
    //             else{
    //                 ans += left_T*right_T + right_F*left_F;
    //             }
    //         }
    //     }
    //     return ans;
    // }

//✅✅🚀DP-Approach (Tabulation)
        
        int t[201][201][2];
        int solve(string &s, int i,int j, bool isTrue){
        if(i>j) return 0;
        if(i==j){
            if(isTrue==true) return s[i]=='T';
            else return s[i]=='F';
        }
        if(t[i][j][isTrue] != -1) return t[i][j][isTrue];
        int ans=0;
        for(int k=i+1;k<j;k+=2){
            int left_T = solve(s,i,k-1,true);
            int left_F = solve(s,i,k-1,false);
            int right_T = solve(s,k+1,j,true);
            int right_F = solve(s,k+1,j,false);
            if(s[k]=='&'){
                if(isTrue==true){
                    ans += left_T*right_T; 
                }
                else{
                    ans += left_T*right_F + right_T*left_F + left_F*right_F;
                }
            }
            else if(s[k]=='|'){
                if(isTrue==true){
                    ans += left_T*right_F + left_T*right_T + left_F*right_T;
                }
                else{
                    ans += left_F*right_F;
                }
            }
            else if(s[k]=='^'){
                if(isTrue==true){
                    ans += left_T*right_F + right_T*left_F;
                }
                else{
                    ans += left_T*right_T + right_F*left_F;
                }
            }
        }
        return t[i][j][isTrue]=ans%1003;
    }
    int countWays(int N, string s){
        int i=0,j=N-1;
        memset(t,-1,sizeof(t));
        return solve(s,i,j,true);
    }
    
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends