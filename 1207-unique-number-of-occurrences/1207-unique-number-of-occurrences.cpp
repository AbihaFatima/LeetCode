class Solution {
public:
    //SC:O(N)
    //TC:O(N)
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it : arr){
            mp[it]++;
        }
        bool ans;
        set<int>st;
        for(int i=0;i<arr.size();i++){
            //insert the key's value pair in a set.
            st.insert(mp[arr[i]]);
            if(st.size()==mp.size()) ans=true;
            else ans=false;
        }
        return ans;
    }
};