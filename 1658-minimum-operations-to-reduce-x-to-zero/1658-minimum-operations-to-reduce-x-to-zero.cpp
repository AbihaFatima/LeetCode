class Solution {
public:
    //Approach: Sliding Window Approach
    //Time Complexity: O(N)
    //Space Complexity: O(1)
    int minOperations(vector<int>& nums, int x) {
        int sumArr = 0, n=nums.size();
        for(int i=0;i<n;i++){
            sumArr += nums[i];
        }
        int target = sumArr-x, currSum=0;
        int start=0,maxLen=0;
        bool found=false;
        //Finding the length of longest subarray equal to target
        for(int end=0;end<n;end++){
            currSum+=nums[end];
            while(start<=end && currSum>target){
                currSum-=nums[start++];
            }
            if(currSum==target){
                found=true;
                maxLen = max(maxLen,end-start+1);
            }
        }
        //The answer would be total number of elements minus the max lenth of subarray
        return found ? n-maxLen : -1;
    }
};