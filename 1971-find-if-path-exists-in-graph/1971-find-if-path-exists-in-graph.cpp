class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited,int destination){
        if(destination == node) return true;
        visited[node] = true;

        //traverse its neighbours
        for(int n : adjList[node]){
            if(!visited[n]) 
                if(dfs(n, adjList, visited, destination)) 
                    return true;
            
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //build adjList
        vector<vector<int>> adjList(n);
        for(auto &e : edges){
            int u=e[0], v=e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        //make visited vector of nodes
        vector<bool> visited(n, false);
        return dfs(source, adjList, visited, destination);
    }
};