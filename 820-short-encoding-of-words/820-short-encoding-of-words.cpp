class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        //Making a set to store all the distinct words
        unordered_set<string> s(words.begin(),words.end());
        
        //Iterate in the set and erase all suffixes of the string so that will have length of shortest reference of words
        for(auto word : s){
            //We are starting with 1 not zero as it would erase the entire string if we start from 0
            for(int i=1;i<word.size();i++){
                s.erase(word.substr(i));
            }
        }
        int ans=0;
        //Adding 1 because of number of hashes is equal to number of strings remaining in the set
        for(auto word: s){
            ans += word.size()+1;
        }
        return ans;
    }
};