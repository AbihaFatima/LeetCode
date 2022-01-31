//Time Complexity: O(N)
//Space Complexity: O(N)

class MyHashMap {
private:
    int prime;
    vector<list<pair<int,int>>>table;
    int hash(int key){
        return key%prime;
    }
public:
    MyHashMap():prime(10007), table(prime) {
        
    }
    //Adding the key value pair to hashmap
    void put(int key, int value) {
        int h = hash(key);
        auto &list = table[h];
        for(auto &it:list){
            if(it.first == key){
                it.second = value;
                return;
            }
        }
        table[h].push_back({key,value});
    }
    
    //Returns the value stored in that key
    int get(int key) {
        int h = hash(key);
        auto &list = table[h];
        for(auto &it:list){
            if(it.first==key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        auto &list = table[h];
        for(auto it:list){
            if(it.first==key){
                table[h].remove(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */