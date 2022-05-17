class Solution {
public:
    string convertToTitle(int n) {
        string str="";
        while(n--){ //example n=28 -> AB
            int i = n%26;   //so i=28%26 = 2
            str+='A'+i;     //'A'+2 => B 
            n/=26;          //n=28/26 = 1 now again loop will execute; i=1%26=0 => 'A'+0=>A
        }
        reverse(str.begin(),str.end());// str=BA after reversing AB
        return str;
    }
};