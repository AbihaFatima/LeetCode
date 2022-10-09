class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ele = *max_element(nums.begin(),nums.end());
        int len=0, maxLen=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                len++;
                maxLen = max(maxLen,len);
            }
            else len=0;
        }
        return maxLen;
    }
};