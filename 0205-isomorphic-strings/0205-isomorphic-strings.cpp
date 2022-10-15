class Solution {
public:
    //Using 2 hashmaps
    
//     bool isIsomorphic(string s, string t) {
        
//         if (s.length() != t.length())
//             return false;
        
//         unordered_map<char, char>m1;
//         unordered_map<char, char>m2;
        
//         for (int i = 0; i < s.length(); i++) {
//             if (m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end())             {
//                 m1[s[i]] = t[i];
//                 m2[t[i]] = s[i];
//             } else {
//                 if (m1.find(s[i]) != m1.end() && (m1[s[i]] != t[i]))
//                     return false;
//                 if (m2.find(t[i]) != m2.end() && (m2[t[i]] != s[i]))
//                     return false;
//             }
//         }
        
//         return true; 
//     }
    
    //Using Single Hashmap
    bool isoCheck(string &s, string &t){
        unordered_map<char,char>mp;
        if(s.length() < t.length()) return false;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[i]) return false;
            }
            else
                mp[s[i]] = t[i];
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t){
        return isoCheck(s,t) && isoCheck(t,s);
    }
};