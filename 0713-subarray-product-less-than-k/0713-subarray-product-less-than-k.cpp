class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int left=0, right=0, product=1;
        int res=0;
        for(right=0;right<size(nums);right++){
            product *= nums[right];
            while(product>=k && left<=right){
                product /= nums[left];
                left++;
            }
            res += right-left+1; //add the size of the curr window;
        }
        return res;
    }
};