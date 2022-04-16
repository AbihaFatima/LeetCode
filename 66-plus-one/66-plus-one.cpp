class Solution {
public:
    vector<int> plusOne(vector<int>& digit) {
        int n = digit.size();
        for(int i = n-1 ; i>=0; i--){
            if(digit[i]==9){
                digit[i]=0;
            }
            else{
                digit[i]++;
                return digit;
            }
        }
        digit[0]=1;
        digit.push_back(0);
        return digit;
    }
};