class Solution {
public:
    /*
    Approach: Using two maps
    TC: O(N * K) where N is the number of words and K is the word length
    SC: O(N * K)
    */
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            map<char,char>m1;
            map<char,char>m2;
            bool flag = true;
            for(int j=0;j<words[i].size();j++){
                //pattern[j] to word[i][j]
                auto it = m1.find(pattern[j]); //find the character in the pattern
                auto it2 = m2.find(words[i][j]); //find the character in the word
                
                //if not found
                //Mapping from pattern to word
                //word = "mee" pattern = "abb"
                if(it == m1.end()){
                    m1.insert({pattern[j],words[i][j]}); //a->m
                }
                else{
                    if(it->second != words[i][j]){
                        flag = false;
                        break;
                    }
                }
                
                //mapping from word to pattern
                if(it2 == m2.end()){
                    m2.insert({words[i][j],pattern[j]}); //m->a
                }
                else{
                    if(it2->second != pattern[j]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag == true) ans.push_back(words[i]);
        }
        
        return ans;
    }
};