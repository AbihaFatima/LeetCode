class Solution {
public:
    bool isVowel(char ch){
       if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
       {
           return true;
       }
        else
            return false;
    }
    
    //SC: O(N) TC: O(N)
    // string reverseVowels(string s) {
    //     int n =s.size();
    //     vector<int>v;
    //     for(int i=0 ; i<n;i++){
    //         if(isVowel(s[i])){
    //             v.push_back(i);
    //         }
    //     }
    //     int start=0, end=v.size()-1;
    //     while(start<end){
    //         swap(s[v[start++]],s[v[end--]]);
    //     }
    //     return s;
    // }
    
    //SC:O(1) TC:O(N)
    //Two Pointer Approach
    string reverseVowels(string s){
        int left=0, right=s.length()-1;
        while(left < right){
            if(isVowel(s[left]) && isVowel(s[right])){
                swap(s[left++],s[right--]);
            }
            if(!isVowel(s[left])) left++;
            if(!isVowel(s[right])) right--;
        }
        return s;
    }
};