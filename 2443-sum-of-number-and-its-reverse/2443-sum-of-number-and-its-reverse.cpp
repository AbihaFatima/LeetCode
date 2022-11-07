class Solution {
public:
    int reverseNum(int num){
        int ans = 0;
        while(num){
            ans = ans*10 + num%10;
            num/=10;
        }
        return ans;
    }
    bool sumOfNumberAndReverse(int num) {
        if(num == 0) return true;
        for(int i=1;i<=num;i++){
            if(reverseNum(i) + i == num) return true;
        }
        return false;
    }
};