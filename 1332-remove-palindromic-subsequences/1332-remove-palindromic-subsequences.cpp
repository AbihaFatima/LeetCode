class Solution {
public:
    bool isPalindrome(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.length()==0) return 0;
        if(isPalindrome(s)==true) return 1;
        else return 2;
    }
};