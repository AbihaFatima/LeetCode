class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
        in.push_back(newIn);
        sort(in.begin(),in.end());
        vector<vector<int>> res;
        res.push_back(in[0]);
        int j=0;
        for(int i=1;i<in.size();i++){
            if(res[j][1] >= in[i][0]){
                res[j][1] = max(res[j][1],in[i][1]);
            }
            else{
                res.push_back(in[i]);
                j++;
            }
        }
        return res;
    }
};