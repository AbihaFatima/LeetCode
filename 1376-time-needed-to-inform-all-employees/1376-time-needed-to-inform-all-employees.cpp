class Solution {
public:
    //DFS Approach
    //TC: O(N) SC:O(N)
    unordered_map<int, vector<int>> adj;
    int ans=0;
    void dfs(int emp, vector<int>& informTime, int time){
        ans = max(ans,time);
        for(auto e: adj[emp]){
            time += informTime[emp];
            dfs(e,informTime,time);
            time -= informTime[emp];
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //Create a graph using manager array
        for(int i=0;i<size(manager);i++){
            adj[manager[i]].push_back(i);
        }
        int time=0;
        dfs(headID, informTime, time);
        return ans;
    }
};