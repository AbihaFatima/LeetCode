class Solution {
public:
//TC: O(N log M), N is numbers in nums array and M is largest num amongst that array, SC:O(N)
    int res = 0;
    int divisorSum(int n){
        int ans = 1 + n; //as mentioned in question we have to find another pair excluding (1,n)
        int countDivisors = 2;
        for(int i = 2; i*i <= n;i++){
            if(n%i == 0){
                int x = n/i;
                if(i == x){ //add this divior only once if its same that is perfect square condition
                    countDivisors++;
                    ans += i;
                }
                else if(i != x) { //if thats just a normal pair add twice
                    countDivisors += 2;
                    ans += i + x;
                }
            }
            if(countDivisors > 4) break;
        }
        return (countDivisors > 4 || countDivisors < 4) ? 0 : ans;
    }

    int sumFourDivisors(vector<int>& nums) {
        for(int n : nums){
            res += divisorSum(n);
        }
        return res;
    }
};