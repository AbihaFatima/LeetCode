class Solution {
public:
    bool isVowel(char ch){
       // if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
       //         ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
       // {
       //     return true;
       // }
       //  else
       //      return false;
        switch(ch){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
                break;
            default : return false;
        }
    }
    string reverseVowels(string s) {
        int n =s.size();
        vector<int>v;
        for(int i=0 ; i<n;i++){
            if(isVowel(s[i])){
                v.push_back(i);
            }
        }
        int start=0, end=v.size()-1;
        while(start<end){
            swap(s[v[start++]],s[v[end--]]);
        }
        return s;
    }
};