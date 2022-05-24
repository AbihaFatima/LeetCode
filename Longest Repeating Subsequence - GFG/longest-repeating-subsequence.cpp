// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string S1){
		    string S2=S1;
		    int n = S1.size();
		    int m=n;
    		int t[n+1][m+1];
            memset(t,-1,sizeof(t));
            //Initialize the table
            for(int i=0;i<n+1;i++){
                for(int j=0;j<m+1;j++){
                    if(i==0 || j==0){
                        t[i][j]=0;
                    }
                }
            }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<m+1;j++){
                    if(S1[i-1]==S2[j-1] && i!=j){
                        t[i][j] = 1 + t[i-1][j-1];
                    }
                    else{
                        t[i][j] = max(t[i-1][j],t[i][j-1]);
                    }
                }
            }
            return t[n][m];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends