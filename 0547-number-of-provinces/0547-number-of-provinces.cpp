class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int>&vis, int i,int n){
        vis[i]=1;
        for(int it=0;it<n;it++){
            if(isConnected[it][i]==1 && vis[it]==0){ //nodes i and it are connected but 'it' is not visited
                dfs(isConnected, vis, it, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(isConnected, vis,i,n);
            }
        }
        return count;
    }
};