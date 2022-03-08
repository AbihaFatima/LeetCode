class Solution {
    //Time Complexity : O(m.n)
    //Space Complexity : O(m.n)
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int rows = grid.size();
        int cols = grid[0].size();
        int ones=0,twos=0,ans=0;
        
        //Count number of 2's and 1's and push all 2's in queue
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 2){
                    twos++;
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    ones++;
                }
            }
        }
        
        //if there are no fresh oranges (ones) present, time required is zero
        if(ones == 0) return 0;
        
        //els If there are no rotten oranges, fresh oranges will not rot and we will have to return (-1)
        else if(twos == 0) return -1;
        
        // count1 stores the number of unvisited nodes or oranges which are 
        // going to affect its neighbours at the current moment
        // count2 is going to store number of childs of the oranges in the current level
        int count1=twos, count2=0;
        // The first level is already rotten, 
        // still we are counting it and hence at the end we return (ans-1) instead of ans.
        
        //BFS traversal
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            // Everytime we pop, unvisited oranges in current level decreases by one, hence count1-- (That is decrementing number of 2's)
            count1--;
            
            // Now we put forward four conditions to check in four directions of the current orange, But for that to work, the position should exist, 
            // i.e. it should not cross the bounds of the grid so using below checkValid Function
            
            //Check for Top Direction
            if(checkValid(i+1,j,rows,cols) && grid[i+1][j]==1){
                // 1(fresh orange) becomes 2 (Rotten Orange) 
                // and number of children i.e. count2 increased by one
                // and lets add it to the queue to check if it has any children later
                q.push({i+1,j});
                grid[i+1][j] = 2;
                count2++;
                ones--;
            }
            //Check for Bottom Direction
            if(checkValid(i-1,j,rows,cols) && grid[i-1][j]==1){
                q.push({i-1,j});
                grid[i-1][j] = 2;
                count2++;
                ones--;
            }
            //Check for Left Direction
            if(checkValid(i,j-1,rows,cols) && grid[i][j-1]==1){
                q.push({i,j-1});
                grid[i][j-1] = 2;
                count2++;
                ones--;
            }
            //Check for Right Direction
                if(checkValid(i,j+1,rows,cols) && grid[i][j+1]==1){
                q.push({i,j+1});
                grid[i][j+1] = 2;
                count2++;
                ones--;
            }
            
            if(count1 == 0){ //Traversed for all 2's
                // count1 is zero means we have completed traversing the current level of the graph
                // and hence one unit of time is passed. So we increrment ans
                // lets go to next level, for that count2 becomes count1 and count2 becomes zero, 
                // i.e. children are upgraded to current generation and child count starts again from zero.
                ans++;
                count1 = count2;
                count2 = 0;
            }
        }
        
        if(ones > 0) return -1;
        
        //Returning the answer
        return ans-1;
    }
    
    bool checkValid(int i,int j,int rows, int cols){
        if(i<0 || i>=rows || j<0 || j>=cols){
            return false;
        }
        return true;
    }
};