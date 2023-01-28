class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>>ans;
        if(size(f)==0 || size(s)==0) return ans;
        int i=0,j=0;
        while(i<size(f) and j<size(s)){
            int a = max(f[i][0],s[j][0]);
            int b = min(f[i][1],s[j][1]);
            if(a<=b) ans.push_back({a,b});
            if(f[i][1] > s[j][1]) j++;
            else i++;
        }
        return ans;
    }
};