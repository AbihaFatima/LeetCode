class Solution {
    bool isCyclic(vector<vector<int>>& adj,vector<int>& visited,int curr){
        if(visited[curr] == 2) return true;
        visited[curr]=2;
        for(int i=0;i<adj[curr].size();++i)
            if(visited[adj[curr][i]]!=1)
                if(isCyclic(adj,visited,adj[curr][i]))
                    return true;
        visited[curr] = 1;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        /*https://www.geeksforgeeks.org/fast-io-for-competitive-programming/*/
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        //make a directed graph
        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(isCyclic(adj,visited,i))
                    return false;
            }
        }
        return true;
    }
};