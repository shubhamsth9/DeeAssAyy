class MyHashSet {
private:
    const static int n = 1000001;
    vector<int> myHash;
public:
    MyHashSet() {
        myHash.resize(1000001, -1);
    }
    
    void add(int key) {
        if(myHash[key%n] == -1 || myHash[key%n] == key){
            myHash[key%n] = key;
        }
        else{
            int i = key;
            while(myHash[i%n] != -1){
                if(myHash[i%n] == key) break;
                i++;
            }
            myHash[i%n] = key;
        }
    }
    
    void remove(int key) {
        if(myHash[key%n] == -1 || myHash[key%n] == key){
            myHash[key%n] = -1;
        }
        else{
            int i = key;
            while(myHash[i%n] != key){
                if(myHash[i%n] == -1) break;
                i++;
            }
            myHash[i%n] = -1;
        }
        
    }
    
    bool contains(int key) {
        if(myHash[key%n] == -1)return false;
        if(myHash[key%n] == key) return true;
        else{
            int i = key;
            while(myHash[i%n] != key){
                if(myHash[i%n] == -1) return false;
                i++;
            }
            if(myHash[i%n] == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */