class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>>res;
        sort(begin(in),end(in));
        int j=0;
        res.push_back(in[0]);
        for(int i=1;i<in.size();i++){
            if(res[j][1] >= in[i][0]){
                //Merge
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