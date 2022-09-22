
class Solution {
public:
//     //Refer Notes attached to this problem for brute-force to optimal approach
//     //TC: 3*O(N) ~ O(N)
//     //SC: O(1) (inplace algorithm)
//     void nextPermutation(vector<int>& nums) {
//     // initialize variable:
//     int breakPoint = -1;

//     // find a breakpoint:
//     for (int i = nums.size() - 1; i > 0; i--)
//     {
//         if (nums[i] > nums[i - 1])
//         {
//             breakPoint = i - 1;
//             break;
//         }
//     }

//     // if no breakpoint
//     if (breakPoint < 0)
//     {
//         reverse(nums.begin(), nums.end());
//         return;
//     }

//     // if found a breakpoint
//     for (int i = nums.size() - 1; i >= 0; i--)
//     {
//         if (nums[i] > nums[breakPoint])
//         {
//             swap(nums[breakPoint], nums[i]);
//             reverse(nums.begin() + breakPoint + 1, nums.end());
//             break;
//         }
//     }
//     }
    
    /*
    nums = [1,3,2,5,4]
    breakPoint = 2 nums[2]=2
    ans = [1,3,4,2,5]
    */
    void nextPermutation(vector<int>& nums) {
        int breakPoint = -1;
        int n = nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                breakPoint = i-1;
                break;
            }
        }
        if(breakPoint < 0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i] > nums[breakPoint]){
                swap(nums[breakPoint],nums[i]);
                reverse(nums.begin()+breakPoint+1,nums.end());
                break;
            }
        }
    }
};