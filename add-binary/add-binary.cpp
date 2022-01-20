class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1; // we crete i pointer for string a and we have to start adding from right to left
        int j = b.size()-1;
        string res;
        int carry = 0;
        while(i>=0 || j>=0){
            int sum = carry;
            
            // Now, we subtract by '0' to convert the numbers from a char type into an int, so we can perform operations on the numbers
            
            if(i>=0) sum += a[i--] - '0';
            if(j>=0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;// getting carry depend on the quotient we get by dividing sum / 2 that will be our carry. Carry could be either 1 or 0 
			// if sum is 0 res is 1 & then carry would be 0;
            // if sum is 1 res is 1 & carry would be 0
            res += (sum%2 +'0'); // just moduling the sum so, we can get remainder and add it into our result
        }
        if(carry != 0) res += (carry+'0'); // we gonna add it into res until carry becomes 0;
        reverse(res.begin(),res.end()); // revese the answer we get & convt to string and return by the help of result;
        return res;
    }
};