//Just like Roman to Integer, this problem is most easily solved using a lookup table for the conversion between digit and numeral. In this case, we can easily deal with the values in descending order and insert the appropriate numeral (or numerals) as many times as we can while reducing the our target number (N) by the same amount.
//Once N runs out, we can return ans.


class Solution {
public:
    const int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const string rom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        string res="";
        for(int i=0;num;i++){
            while(val[i]<=num){ 
                res += rom[i];
                num -= val[i];
            }
        }
        return res;
    }
};