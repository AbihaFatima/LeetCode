class Solution {
public:
    int reverse(int x) {
        int revNum=0;
        while(x!=0){
            if(revNum > INT_MAX/10 || revNum < INT_MIN/10) return 0; //to check whether revNum will overflow before we multiply it by 10.
            else{
                revNum = revNum*10 + x%10;
                x = x/10;
            }
        }
        return revNum;
    }
};