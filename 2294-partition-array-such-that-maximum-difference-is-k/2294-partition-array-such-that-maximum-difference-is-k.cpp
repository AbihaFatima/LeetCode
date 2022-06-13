class Solution {
public:
    //TC: O(NlogN)
    //SC: O(1)
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0,count=0;
        for(int i=0;i<n;i++){
            if(nums[i]-nums[j] > k){
                j=i;
                count++;
            }
        }
        return count+1;
    }
};