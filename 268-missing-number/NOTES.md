Similar Approach:
```
int a = 0 , b = 0;
for(0 to n){
a = a^arr[i]; // let say array is 3,0,1 then a will store  3^0^1
b = b^(i+1);  // here b will store 1^2^3
}
return a^b; //a^a=0 ,so the number present both in a and b will cancel out(become zero ) and the element which is not present in a. 
            //i.e 2 will be returned by the function.
```
​
