class Solution {
public:
    //Using Recursion
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        combination(n, n, "", res);
        return res;
    }
    
    void combination(int l, int r, string path, vector<string>& res){
        if (l < 0 || r < 0 || l > r) //Base Case
            return;
        
        if (l == 0 && r == 0)
            res.push_back(path);
        
        combination(l-1, r, path+'(', res);
        combination(l, r-1, path+")", res);
    
    }
};