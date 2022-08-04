class Solution {
    bool isDigit(char str){
        return str >= '0' && str <= '9';
    }
public:
    int myAtoi(string str) {
        int len = str.length();
        int index=0;
        //Ignoring whitespaces before digit
        while(str[index]==' ' && index < len){
            index++;
        }
        int ans = 0;
        
        //Finding if number is negative or positive
        bool isNegative = false;
        if(index < len){
            if(str[index] =='-'){
                isNegative = true;
                index++;
            }
            else if(str[index] == '+'){
                index++;
            }
        }
        
        while(index < len && isDigit(str[index])){
            int digit = str[index] - '0';
            // to avoid integer overflow
            if(ans > (INT_MAX / 10) || (ans == (INT_MAX / 10) && digit > 7)){
              return isNegative ? INT_MIN : INT_MAX;
            }
            
            ans = ans*10 + digit;
            index++;
        }
        return (isNegative) ? -ans : ans;
    }
};