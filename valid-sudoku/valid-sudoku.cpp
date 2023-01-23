class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> r(9),c(9),box(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                //If there is no number present then continue
                if(board[i][j]=='.') continue;
                
                int curr = board[i][j];
                //Check if the current number is already present i.e it will have count>=1
                if(r[i].count(curr) || c[j].count(curr) || box[(i/3*3)+j/3].count(curr)){
                    return false;
                }
                
                //if the number is not present then add it to the set 
                r[i].insert(curr);
                c[j].insert(curr);
                box[(i/3*3)+j/3].insert(curr);
            }
        }
        return true;
    }
};