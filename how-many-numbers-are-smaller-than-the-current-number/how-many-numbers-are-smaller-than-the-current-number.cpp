class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        //create a map, as unordered map doesnot allow multiple entries
        unordered_map<int, int> smaller;
        
        vector<int>count(nums); //create a duplicate vector of nums
        
        //sort the vector;
        sort(count.begin(),count. end());
        
        for(int i=0;i<count.size();i++){
            smaller.insert({count[i],i});
        }
        
        for(int i=0;i<nums.size();i++){
            count[i] = smaller[nums[i]];
        }
        
        return count;
    }
};