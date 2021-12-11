class Solution {
public:
/*
First add elements and their index in a vector of pair format {a[i],i}
then reverse sort them
Now add first k elements in a temporary array of vector of pair format {i,a[i]}
Now sort this temp and add elements to ans
*/
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<pair<int,int>> v;
        
        for(int i = 0 ; i < n ; i++)
        {
           v.push_back({nums[i],i}); 
        }    
        
        sort(begin(v),end(v));
        reverse(begin(v),end(v));
        
        vector<pair<int,int>> res;
        
        for(int i = 0 ; i < k ; i++)
        {
             res.push_back({v[i].second,v[i].first});
        }   
        
        
        sort(begin(res),end(res));
        
        vector<int> ans;
        
        for(int i = 0 ; i < k ; i++)
        {
            ans.push_back(res[i].second);
        }   
        
        return ans;
    }
};