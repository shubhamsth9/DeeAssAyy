class MyHashMap {
public:
    const static int n = 1e7+1;
    vector<int> mapp;
    
    MyHashMap() {
        mapp.resize(n, -1);    
    }
    
    void put(int key, int value) {
        mapp[key] = value;
    }
    
    int get(int key) {
        return mapp[key];
    }
    
    void remove(int key) {
        mapp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */