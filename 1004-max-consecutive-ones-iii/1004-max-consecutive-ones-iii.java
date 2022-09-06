class Solution {
    public int longestOnes(int[] nums, int k) {
        
        int start=0, end=0, ans=0, numZeroes=0;
        
        for(end=0;end<nums.length;end++){
            if(nums[end] == 0) numZeroes++;
            
            if(numZeroes > k)
                if(nums[start++]==0)
                    numZeroes--;
            
            if(numZeroes <= k)
                ans = Math.max(ans, end-start+1);
        }
        return ans;
    }
}