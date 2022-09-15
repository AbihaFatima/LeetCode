class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2 != 0) return {};
        sort(changed.begin(),changed.end());
        map<int,int>m;
        vector<int>ans;
        //Add frequencies of each element in the map
        for(int i=0;i<n;i++){
            m[changed[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(m[changed[i]] == 0) continue;
            
            if(m[changed[i]*2] == 0) return {};
            
            ans.push_back(changed[i]);
            m[changed[i]]--;
            m[changed[i]*2]--;
        }
        
        return ans;
    }
};