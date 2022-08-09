class Solution {
public:
    //DP Appraoch - Iterative
    
    vector<vector<int>> ans;
    vector<vector<int>> generate(int n) {
        for(int i=0;i<n;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){
                row[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(row);
        }
        return ans;
    }
};