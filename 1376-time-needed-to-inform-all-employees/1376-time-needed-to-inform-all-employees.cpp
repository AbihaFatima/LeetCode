class Solution {
public:
    // //DFS Approach
    // //TC: O(N) SC:O(N)
    // unordered_map<int, vector<int>> adj;
    // int ans=0;
    // void dfs(int emp, vector<int>& informTime, int time){
    //     ans = max(ans,time);
    //     for(auto e: adj[emp]){
    //         time += informTime[emp];
    //         dfs(e,informTime,time);
    //         time -= informTime[emp];
    //     }
    // }
    // int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    //     //Create a graph using manager array
    //     for(int i=0;i<size(manager);i++){
    //         adj[manager[i]].push_back(i);
    //     }
    //     int time=0;
    //     dfs(headID, informTime, time);
    //     return ans;
    // }
    
    //BFS Approach
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<manager.size();i++){
            adj[manager[i]].push_back(i);
        }
        int ans=0;
        //push employeeID and duration in the queue
        queue<pair<int,int>>q;
        q.push({headID, 0});
        while(!q.empty()){
            int levelSize = q.size();
            for(int i=0;i<levelSize;i++){
                int emp = q.front().first;
                int time = q.front().second;
                q.pop();
                int totalTime = informTime[emp] + time;
                ans = max(ans,totalTime);
                //push children nodes in queue
                for(auto e: adj[emp]){
                    q.push({e,totalTime});
                }
            }
        }
        return ans;
    }
};