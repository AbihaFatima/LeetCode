class Solution {
public:
    //BFS bipartition Approach
    //Time Complexity: O(N+E) //E for creating adj list, N for coloring
    bool isBipartite(vector<vector<int>> &adj,int n, int src, vector<int>& colorArr){
        queue<int>q;
        q.push(src);
        colorArr[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int color = colorArr[node];
            for(auto it : adj[node]){
                    if(colorArr[it] == colorArr[node]) return false;
                    if(colorArr[it] == -1){
                        q.push(it);
                        colorArr[it] = 1-color;
                    }
                    }
                }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        //Making adjacency list of given array of pairs
        for(int i=0;i<dislikes.size();++i){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int>colorArr(n+1,-1);
        for(int i=1;i<=n;i++){
            if(colorArr[i] == -1){
                if(!isBipartite(adj,n,i,colorArr))
                    return false;
            }
        }
        return true;
    }
};