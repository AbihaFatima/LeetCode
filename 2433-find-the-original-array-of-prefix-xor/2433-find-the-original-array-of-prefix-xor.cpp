class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ans;
        ans.push_back(pref[0]);
        for(int i=0;i<pref.size()-1;i++){
            int x = pref[i]^pref[i+1];
            ans.push_back(x);
        }
        return ans;
    }
};