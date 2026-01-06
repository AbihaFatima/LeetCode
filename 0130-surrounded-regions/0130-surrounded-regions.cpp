class Solution {
public:
    vector<pair<int, int>> dir = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}
    };
    void dfs(int x, int y, vector<vector<char>>& board) {
        board[x][y] = 'T'; // mark safe

        for(auto d : dir) {
            int nx = x + d.first;
            int ny = y + d.second;
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == 'O') {
                dfs(nx, ny, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();

        // Make DFS call from borders which are O
        for (int i = 0; i < m; i++) {
            if(board[i][0] == 'O') dfs(i,0,board); //left border
            if(board[i][n-1] == 'O') dfs(i,n-1,board); //right border
        }

        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O') dfs(0,j,board); //top border
            if(board[m-1][j] == 'O') dfs(m-1,j,board); //bottom border
        }
        
        // Flip all remaining 'O' -> 'X' and restore 'T' -> 'O'
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }

    }
};
