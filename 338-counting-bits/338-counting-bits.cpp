class Solution {
public:
    //Brute-force Approach
    //Time Complexity : O(nlogn)
    //Space Complexity : O(1)
    // vector<int> countBits(int n) {
    //     vector<int>res;
    //     for(int i=0;i<=n;i++){
    //         int sum = 0;
    //         int num = i;
    //         //Counting number of 1's in the binary representation of i or num
    //         while(num!=0){
    //             sum = sum + num%2;
    //             num = num/2;
    //         }
    //         res.push_back(sum);
    //     }
    //     return res;
    // }
    
    //Most Optimised Approach is by using DP
    //Time Complexity : O(N)
    //Approach : No. of 1s in binary representation of current number = No. of 1s in binary representation of half of the current number + current number%2.
    vector<int> countBits(int n) {
        vector<int>result(n+1);
        result[0] = 0;
        for(int i=1;i<n+1;i++){
            result[i] = result[i/2] + (i%2);
        }
        return result;
    }
};