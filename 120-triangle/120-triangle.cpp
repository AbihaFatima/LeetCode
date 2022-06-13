class Solution {
public:
    //DP Approach
    //Space Complexity: O(1)
    //TC: O(N^2) \U0001f914maybe
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};