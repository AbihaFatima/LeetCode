unordered_map<char, string> dir({
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}});
class Solution {
private:
    void dfs(int idx, int &len, string str, vector<string>& ans, string& digits){
        if(idx == len) ans.push_back(str);
        else{
            string letterCombo = dir[digits[idx]];
            for(auto i: letterCombo) 
                dfs(idx+1, len, str+i, ans, digits);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size() == 0) return ans;
        int len = digits.length();
        dfs(0, len, "", ans, digits);
        return ans;
    }
};