class Solution {
public:
    int vowel(vector<char>ch){
        int count=0;
        for(int i=0;i<ch.size();i++){
            if(ch[i]=='a' || ch[i]=='e' || ch[i]=='i' || ch[i]=='o' || ch[i]=='u' || ch[i]=='A' || ch[i]=='E' || ch[i]=='I' || ch[i]=='O' || ch[i]=='U'){
                count++;
            }
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        vector<char>s1,s2;
        int n = s.size();
        for(int i=0;i<n/2;i++){
            s1.push_back(s[i]);
        }
        for(int i=n/2;i<n;i++){
            s2.push_back(s[i]);
        }
        if(vowel(s1) == vowel(s2)){
                return true;
        }
        else
            return false;
    }
};