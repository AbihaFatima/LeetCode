class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> vc(r,vector<int>(c));
        
        if((r*c)!=(mat.size()*mat[0].size())) 
            return mat;
        
        vector<int> y;
        for(int p=0;p<mat.size();p++){
            for(int q=0;q<mat[0].size();q++){
                y.push_back(mat[p][q]);
            }
        }   
        
        auto it = y.begin();
        for(int i=0;i<r;i++){
            for(int j = 0;j<c;j++){
                vc[i][j]=*it;
                it++;
            }
        }
        return vc;
    }
};