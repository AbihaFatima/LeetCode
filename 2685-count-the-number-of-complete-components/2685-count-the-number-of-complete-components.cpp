class Solution {
public:
    //graph is set to be completed if total edges in a component = V(V-1)/2; v is total vertices in that component

    //Approach:
    //1. First find all connected components using BFS/DFS
    //2. For each component, count how many nodes and edges it contains.
    //3. If the number of edges equals k*(k-1)/2, then the component is complete.

    void dfs(int currNode, vector<vector<int>>& adj, vector<bool>& visited, int &totalNodes, int &edges){

        visited[currNode] = true;
        totalNodes++;
        //calculate edges of this node
        edges += adj[currNode].size();

        for(int neighbour : adj[currNode]){
            if(!visited[neighbour]){
                dfs(neighbour,adj, visited, totalNodes, edges);
            }
        }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        //build adjacenyList
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int completedComponents = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int totalNodes=0;
                int edges = 0;
                dfs(i, adj, visited, totalNodes, edges);
                edges/=2; //as graph is undirected 
                if(edges == totalNodes * (totalNodes-1)/2){
                    completedComponents++;
                }
            }
        }

        return completedComponents;
    }
};