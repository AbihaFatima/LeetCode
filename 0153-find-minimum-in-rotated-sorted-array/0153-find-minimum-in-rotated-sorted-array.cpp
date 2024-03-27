class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0, end=nums.size()-1;
        while(start <= end){
            int mid = (start+end)/2;
            //case: array is sorted
            if(nums[start]<=nums[end]) return nums[start];
            
            //case: mid is greater than end means array is rotated and minimum lies on right
            if(nums[mid] > nums[end]) start=mid+1;
            
            else end=mid;
        }
        return nums[start];
    }
};