class Solution {
public:
    int roman(char r){
        int num;
            switch(r) {
                case 'I': num= 1;break;
                case 'V': num= 5; break;
                case 'X': num= 10; break;
                case 'L': num= 50; break;
                case 'C': num= 100; break;
                case 'D': num= 500; break;
                case 'M': num= 1000; break;
            }
        return num;
    }
    
    int romanToInt(string s) {
        int i,n,p=0,ans=0;
        n = s.size()-1;
        for(i=n;i>=0;i--){
            if(roman(s[i]) >= p)
                ans = ans + roman(s[i]);
            else
                ans = ans - roman(s[i]);
            p = roman(s[i]);
        }
        return ans;
    }
};