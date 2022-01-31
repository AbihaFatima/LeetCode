// //Basic Implementation:
// //Time Complexity : O(N); average : O(1)
// //Space Complexity: O(N)

// class MyHashSet {
// private:
//     int prime;
//     vector<list<int>> table; //Creating a vector of list for hashtable
//     int hash(int key){
//         return key%prime; //prime here is we are considering max number of elements let's say 10007
//     }
//     list<int>::iterator search(int key){
//         int h = hash(key);
//         return find(table[h].begin(),table[h].end(),key);//Find whether the key is present or not
//     }
// public:
//     MyHashSet(): prime(10007), table(prime) {
//     }//Constructor initializing the value of prime as 10007 and list of size prime
    
//     void add(int key) {
//         int h = hash(key);
//         if(!contains(key)){//If the key is not present then push_back key
//             table[h].push_back(key);
//         }
//     }
    
//     void remove(int key) {
//         int h = hash(key);
//         auto it = search(key);
//         if(it!=table[h].end()){//If the iterator does not reach till end that means key is present
//             table[h].erase(it);
//         }
//     }
    
//     bool contains(int key) {
//         int h = hash(key);
//         return search(key)!=table[h].end(); //if the search key reaches end(it will return false as key is not present)
//     }
// };

//Troll Implementation(Optimised Approach)
//Time Complexity : O(1)
//Space Complexity : O(1)

class MyHashSet {
private:
    vector<bool>table;
public:
    MyHashSet(): table(1e6+1,false){}
    
    void add(int key) {
        table[key] = true;
    }
    void remove(int key) {
        table[key] = false;
    }
    bool contains(int key) {
        return table[key];
    }
    
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */