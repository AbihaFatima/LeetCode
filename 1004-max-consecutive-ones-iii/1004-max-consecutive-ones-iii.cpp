class Solution {
public:
    //Transalation of Question: Find maximum len subarray with atmost k zeroes
    //Approach: Sliding Window
    //Time Complexity: O(N)
    //Space Complexity: O(1)
    int longestOnes(vector<int>& nums, int k) {
        int numZeroes=0,start=0,end=0,res=0;
        
        for(end=0;end<nums.size();end++){
            
            if(nums[end]==0) numZeroes++;
            
            if(numZeroes > k){
                if(nums[start] == 0) numZeroes--;
                start++;
            }
            if(numZeroes <= k){
                res = max(res, end-start+1);
            }
        }
        return res;
    }
};