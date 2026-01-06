class Solution {
public:
/*
So basically if you look at the rooms vector, it has the nodes that ith node connects to,
which makes it a directed graph and the rooms vector is the adjacenyList, so we are basically maintaining a visited array of nodes
and traversing and checking that can we visit the node from that point, at the end we check if there are any unvisited nodes in the
bool visited array, if so we return false, and if no unvisited nodes that means we are able to open all nodes, hence returning true

TC: O(n + total_keys) ; total_keys = edges so -> O(V+E)
SC: O(N) + O(N) that is recursion stack and visited node
*/

    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited){
        visited[node] = true;
        //check its neighbours
        for(int n: rooms[node]){
            if(!visited[n]) dfs(n, rooms, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, rooms, visited);
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};