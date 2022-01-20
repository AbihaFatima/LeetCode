class Solution {
public:
    //Brute-force approach
    //TimeComplexity : O(NlogN) ; because of sorting
    //SpaceComplexity : O(1)
    int arrayPairSum(vector<int>& nums) {
        int max =0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i=i+2){
            max += min(nums[i],nums[i+1]);
        }
        return max;
    }
};