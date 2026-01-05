class Solution {
public:
    /*
    Approach:
    ---------
    Instead of starting from each cell and checking if water can flow to both oceans,
    we reverse the problem.

    Observation:
    - Water flows from a cell to its neighbor only if the neighbor's height is
    less than or equal to the current cell.
    - So, if we start from the oceans and move "uphill" (to equal or higher height),
    we can find all cells from which water can reach that ocean.

    Steps:
    1. Use DFS starting from all Pacific ocean border cells (top row and left column).
    Mark all cells reachable from Pacific using bitmask = 1.

    2. Use DFS starting from all Atlantic ocean border cells (bottom row and right column).
    Mark all cells reachable from Atlantic using bitmask = 2.

    3. Maintain a single visited matrix using bitmasking:
    - visited[i][j] = 1 → reachable from Pacific
    - visited[i][j] = 2 → reachable from Atlantic
    - visited[i][j] = 3 → reachable from both oceans

    4. During DFS:
    - Only move to neighboring cells with height >= current cell
    - Stop DFS if the cell is already visited for the same ocean

    5. Finally, collect all cells where visited[i][j] == 3.
    */
    //TC & SC: O(m * n)
    vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& visited, int oceanBit){

        // stop if already visited by this ocean
        if (visited[i][j] & oceanBit) return;

        visited[i][j] |= oceanBit;

        for(auto d : dir){
            int x = i + d[0];
            int y = j + d[1];

            //check if coordinates in bound
            if(x >= 0 && x < heights.size() && y>=0 and y < heights[0].size() && heights[x][y] >= heights[i][j]){
                dfs(x,y,heights,visited,oceanBit);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> res;

        //start dfs from top and left egdes and the oceanBit = 1 for pacific
        for(int i=0;i<m;i++) dfs(i, 0, heights, visited, 1);
        for(int j=0;j<n;j++) dfs(0, j, heights, visited, 1);

        //start dfs from right and bottom edges and the oceanBit = 2 for atlantic
        for(int i=0;i<m;i++) dfs(i, n-1, heights, visited, 2);
        for(int j=0;j<n;j++) dfs(m-1, j, heights, visited, 2);

        //now the cells which will flow water to both oceans (the intersection : having visited as 3)
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 3) res.push_back({i,j});
            }
        }
        return res;
    }
};