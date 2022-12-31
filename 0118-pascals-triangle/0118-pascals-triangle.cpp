class Solution {
public:
    //DP Appraoch
    vector<vector<int>> ans;    // initialize n rows
    vector<vector<int>> generate(int n) {
        for(int i=0;i<n;i++){
            vector<int> row(i+1,1); // ith row(0-indexed) has i+1 elements
            for(int j=1;j<i;j++){   
                row[j] = ans[i-1][j] + ans[i-1][j-1];   // 1st and last elements will be 1, rest will be sum of two elements from above row
            }
            ans.push_back(row);
        }
        return ans;
    }
};