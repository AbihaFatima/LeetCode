class Solution {
public:
    int addDigits(int num) {
        for(int i=0;i<num;i++){
            int a = num/10;
            int b = num%10;
            num = a+b;
            if(num/10 < 1){
                break;
            }
        }
        return num;
    }
};