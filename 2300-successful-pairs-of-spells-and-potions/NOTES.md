- Intuition: we will sort the portions array and then find for lowest index of potions for which `spells[i] * potions[index]<success` <br>
- then we will push n-index to the vector where n is size of potion<br>
- Now why should we do this? <br?
- so when we sort potions array lets say spells = [5,1,3] and potions = [1,2,3,4,5] and success =7 <br>
- now if we sort this potions array, as it already sorted doesn't makes any difference for this example.<br>
- now for 0th spell : 5 * [1,2,3,4,5] = [5,10,15,20,25] so here we need find last index for which `spells[i] * potions[index]<success` i.e 5<7, and automatically all the values after it would be greater than 7 so we don't have to multiply and check for all values.<br>
- and so we will push (5-1) => 4 to the answer vector<br>
*Time Complexity: O(n logn) because of sorting <br>
*Space Complexity: O(1) if answer vector is not considered.<br>