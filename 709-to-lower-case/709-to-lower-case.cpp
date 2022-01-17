class Solution {
public:
    char replace(char ch){
        if(ch>=65 && ch<=90){
            ch = ch+32;
        }
        return ch;
    }
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++){
            s[i] = replace(s[i]);
        }
        return s;
    }
};