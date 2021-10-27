class Solution {
public:
    //Two pointer approach
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n= nums.size();
        int i=0,j=n-1;
        
        for(int k=0;k<n;k++)
        {
        while(i<n && nums[i]%2 == 0){
           i+=2;
        }
        while (j>=0 && nums[j]%2!=0){
            j=j-2;
        }
            if(i==n)
                break;
            
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};