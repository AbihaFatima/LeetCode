class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=size(nums);
        int start=0,end=n-1,mid;
        while(start<=end){
            mid=start+(end-start)/2;
            //If array is already sorted
            if(nums[start]<=nums[end]) return nums[start];
            int next=(mid+1)%n, prev=(mid+n-1)%n;
            if(nums[mid]<nums[prev] and nums[mid]<nums[next]) return nums[mid];
            else if(nums[start]<=nums[mid]) start=mid+1;
            else end=mid-1;
        }
        return 0;
    }
};