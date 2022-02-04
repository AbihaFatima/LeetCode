class Solution {
public:
    // //Brute-force approach:
    // int findMaxLength(vector<int>& nums) {
    //     int maxLen=0;
    //     for(int i=0;i<nums.size();i++){
    //         int one=0;
    //         int zero=0;
    //         for(int j=i;j<nums.size();j++){
    //         if(nums[j]==1) one++;
    //         if(nums[j]==0) zero++;
    //         if(one==zero){
    //             maxLen=max(maxLen, j-i+1);
    //         }
    //         }
    //     }
    //     return maxLen;
    // }
    
    //Optimised approach
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        int longest_subarray = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i]==0 ? -1 : 1; 
            if(sum==0){
                if(longest_subarray < i+1){
                    longest_subarray = i+1;
                }
            }
            else if(mp.find(sum) != mp.end()){
                if(longest_subarray < i-mp[sum])
                    longest_subarray = i-mp[sum];
            }
            else
                mp[sum] = i;
        }
        return longest_subarray;
    }
};