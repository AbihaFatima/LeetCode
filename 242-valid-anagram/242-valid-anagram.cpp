class Solution {
public:
    //Sorting Approach takes O(N logN) time
    //O(1) space, but some sorting algorithms do take up some space
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) return false;
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         return (s==t);
//     }
    
    //Hashing Approach TimeComplexity : O(N)
    //SpaceComplexity : O(N)
    bool isAnagram(string s, string t){
        if(s.size() != t.size()) return false;
        unordered_map<char, int> HashMap;
        for(char c : s){
            HashMap[c]++;
        }
        for(char c: t){
            HashMap[c]--;
            if(HashMap[c]<0) return false;
        }
        return true;
    }
};