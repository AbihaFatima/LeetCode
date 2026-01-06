class Solution {
public:
// TC: O(P × L)    [P = number of paths, L = average path length]
// SC: O(P × L) i.e(output) + O(L) i.e(recursion & path)
/*
1.Graph is a DAG, so no cycle handling needed.
2.Use DFS because we must generate all paths.
3.Keep a path vector for the current DFS route.
4.Start DFS from node 0.
5.On entering a node, push it into path.
6.If node == n-1, store a copy of path in result.
7.Otherwise, DFS on all neighbors.
8.After exploring, pop the node (backtracking).
9.Return the result list.
*/
    
    void dfs(int node, vector<vector<int>>& graph, vector<int> path, vector<vector<int>>& result){

        path.push_back(node);
        //stop and push to result vector when the last node is reached
        if(node == graph.size()-1){
            result.push_back(path);
        }
        else{
            //traverse its neighbouring nodes and form a path
            for(int n : graph[node]) dfs(n, graph, path, result);
        }
        
        //Backtrack
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        //starting from source 0 to target -> n-1
        dfs(0, graph, path, result);
        return result;
    }
};