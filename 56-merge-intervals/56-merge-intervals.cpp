class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> ans;
        if(in.size() == 0){
            return ans;
        }
        sort(in.begin(),in.end());
        int j=0;
        ans.push_back(in[0]);
        
        for(int i=1;i<in.size();i++){
            if(ans[j][1] >= in[i][0]){ //overlapping condition
                ans[j][1] = max(ans[j][1],in[i][1]); 
                // ans.push_back({in[j][0],max(in[i][1], in[j][1])}); //-> this is also the correct way
            }
            else{
                j++;
                ans.push_back(in[i]);
                // ans.push_back({in[i][0],in[i][1]}); //alternative way
            }
        }
        return ans;
    }
};