class Solution {
public:
    //TimeComplexity : O(N)
    //SpaceComplexity : O(1)
    string removeKdigits(string num, int k) {
        string result="";
        for(int i=0;i<num.length();i++)
        {
            while(result.size()!=0 && result.back()>num[i] && k!=0)
            {
                result.pop_back();
                k--;
            }
            if(result.size()!=0||num[i]!='0') result.push_back(num[i]);
        }
        while(result.size()!=0 && k--)           
        {
            result.pop_back();
        }
        return (result=="")?"0" :   result;
    }
};