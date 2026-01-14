class Solution {
public:
    //need to find contiguous subarrays having zero, so start with zeroes count and break if we see non zero number
    long long zeroFilledSubarray(vector<int>& nums) {
        long long currZeroes = 0;
        long long res = 0;
        for(int n : nums){
            if(n==0){
                currZeroes++;
                res += currZeroes;
            }
            else{
                currZeroes = 0;
            }
        }
        return res;
    }
};