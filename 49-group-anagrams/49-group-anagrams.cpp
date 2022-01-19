class Solution {
public:
    //Time Complexity : NlogN because of sorting is used
    //Space Complexity : O(N)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 1){
            return {{strs[0]}};
        }
        
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(strs[i].begin(),strs[i].end()); //Sorting the string
            m[strs[i]].push_back(s); //Sorted string is the key and value is initial string
        }
        for(auto i = m.begin();i != m.end();i++){
            res.push_back(i->second);
        }
            
        return res;
    }
};