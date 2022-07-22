class Solution {
public:
    //TC: O(V+E)
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int src)
    {
        vis[src] = true;
        for(int i : adj[src])
            if(!vis[i])
                dfs(adj, vis, i);
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        //we need n-1 edges atleast for n vertices is connection size is lesser means we don't have sufficient edges
        if(connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                dfs(adj, visited, i);
                components++;
            }
        return components - 1;
    }
};