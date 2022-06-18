    /*
    Time Complexity: O(N*L*L) where L is length of a word in array of words
    Space Complexity: O(N) where n is the total words because of hashmap
    */
class WordFilter {
public:
    unordered_map<string, int>mp; //stores preffix and suffix sequence in it
    
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){//cover each word in words
            //storing all possible sequence of prefix and suffix of a word in the hashmap
            string pre = "";
            for(int j=0;j<words[i].size();j++){
                //for prefix
                pre += words[i][j];
                string suf ="";
                
                for(int k=words[i].size()-1;k>=0;k--){
                    //for suffix
                    suf = words[i][k] + suf;
                    mp[pre + "|" + suf] = i+1;//set index i+1 for all possible sequence of a word
                    ////we set i+1 to handle i=0 because by-default map initialized with 0 
                    
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix + "|" + suffix]-1; //if sequence found in hashmap we return its index
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */