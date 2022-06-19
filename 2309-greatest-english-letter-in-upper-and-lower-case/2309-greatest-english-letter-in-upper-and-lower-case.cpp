/*
Time Complexity: O(N) + O(NlogN) = O(NlogN) //sorting the string
Space Complexity: O(N) //Using HashMaps
*/
class Solution {
public:
    string greatestLetter(string s) {
        unordered_map<char,int>mp;//storing string in a hashmap for searching in efficient time
        string ans = "";
        for(auto it : s){
            mp[it]++;
        }
        sort(s.begin(),s.end()); //charaters would be sorted Lexicographically, and so we will get greater characters towards the end
        for(int i=0;i<s.length();i++){
            char u = toupper(s[i]);
            char l = tolower(s[i]);
            if(mp[u] && mp[l]){ //Checks if both upper case and lower case character is present or not
                ans = u;
            }
        }
        return ans; //Returns the character if present else returns empty string
    }
};