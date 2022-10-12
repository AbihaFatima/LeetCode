class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n = nums.size();
        //Herons Formula
        for(int i=2;i<n;i++){
            int a=nums[i-2];
            int b=nums[i-1];
            int c=nums[i];
            float s = (float)(a+b+c)/2;
            if(s>a && s>b && s>c)
                return s*2;
        }
        return 0;
    }
};