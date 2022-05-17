class Solution {
public:
    string convertToTitle(int n) {
        string str="";
        while(n--){
            int i = n%26;
            str+='A'+i;
            n/=26;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};