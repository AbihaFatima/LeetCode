class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int n=size(nums);
        if(n==0) return ans;
        //First Occurence
        int start=0,end=n-1,mid;
        while(start<=end){
            mid=start+((end-start)/2);
            if(target==nums[mid]){
                ans[0]=mid;
                end=mid-1;
            }
            else if(target>nums[mid]) start=mid+1;
            else end=mid-1;
        }
        //Last Occurence
        start=0,end=n-1;
        while(start<=end){
            mid=start+((end-start)/2);
            if(target==nums[mid]){
                ans[1]=mid;
                start=mid+1;
            }
            else if(target<nums[mid]) end=mid-1;
            else start=mid+1;
        }
        return ans;
    }
};