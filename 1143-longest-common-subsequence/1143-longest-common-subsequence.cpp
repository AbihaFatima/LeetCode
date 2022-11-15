class Solution {
public:
    //Approach : Dynamic Programming - Tabulation (Bottom up Approach)
    //Time Complexity : O(m x n) //m is size of 1st string and n is size of 2nd string
    //Space Complexity : O(m x n)
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int table[m+1][n+1];
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) table[i][j]=0; //0th row and 0th column will be having values 0
                else if(text1[i-1] == text2[j-1]) table[i][j] = 1 + table[i-1][j-1]; //if match occurs then 1 + value of previous diagonal element
                else table[i][j] = max(table[i][j-1] , table[i-1][j]); //else max of previous elements
            }
        }
        return table[m][n];
    }
};