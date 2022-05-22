class Solution {
public:
    /*
    Binary Search on Answer(i.e range of sum from max element in nums to sum of all elements)
    
    Time Complexity: O(nlog(sum))
    Space Complexity: O(1)
    */
    int subArrCount(vector<int>& nums, int mid){
        int count=0,temp=0;
        for(int i=0;i<nums.size();i++){
            if(temp+nums[i]<=mid){
                temp+=nums[i];
            }
            else{
                count++;
                temp=nums[i];
            }
        }
        count++;
        return count;
    }
    int splitArray(vector<int>& nums, int m) {
        int low=0,high=0,mid=0,ans=0;
        int n =nums.size();
        for(int i=0;i<n;i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        while(low<=high){
            mid = low+(high-low)/2;
            int count = subArrCount(nums,mid);
            if(count<=m){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};