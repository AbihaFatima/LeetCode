class Solution {
public:
    bool check(string words){
        int h=words.size()-1,l=0;
        while(l<h){
            if(words[l++] != words[h--])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(check(words[i]))
                return words[i];
        }
        return "";
    }
};