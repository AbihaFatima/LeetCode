class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string prefix = "";
        vector<vector<string>>ans;
        sort(products.begin(),products.end());
        for(int i=0;i<searchWord.size();i++){
            prefix += searchWord[i]; //Adding a character of searchWord for every iteration
            vector<string>s; //Vector of string to store the strings matching with prefix (searchWord)
            string sub=""; 
            for(int j=0;j<products.size();j++){
                string s1 = products[j];
                sub = s1.substr(0,i+1);//Making a substring of length of prefix
                if(sub == prefix && s.size()!=3){ //Checking if the substring is equal to the prefix
                    //and if size is greater than 3, then only starting matching strings or minimum lexicographic string would be pushed (because of this we have sorted the products vector)
                    s.push_back(products[j]);
                }
            }
            ans.push_back(s);//Pushing the vector of strings into ans;
            s.clear();//clearing string vector for next group of words(next iteration)
        }
        return ans;
    }
};