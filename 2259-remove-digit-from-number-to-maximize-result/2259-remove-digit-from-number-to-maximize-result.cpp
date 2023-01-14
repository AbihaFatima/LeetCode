class Solution {
public:
    string removeDigit(string number, char digit){
        string ans=" ";
        for(int i=0;i<number.size();i++){
            string s =" ";
            if(number[i] == digit) s = number.substr(0,i) + number.substr(i+1);
            ans = max(ans,s);
        }
        return ans;
    }
};