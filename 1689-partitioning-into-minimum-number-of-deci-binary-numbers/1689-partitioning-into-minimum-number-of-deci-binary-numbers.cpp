class Solution {
public:
    /*
    Here we only have to return the maximum digit in the string of numbers
    */
    int minPartitions(string num) {
        char maximum = '0';
        for(int i=0;i<num.size();i++){
            if(num[i] > maximum)
                maximum = num[i];
        }
        return maximum - '0'; //Returning string to int
    }
};