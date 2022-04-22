struct node{
public:
    int key, val;
    node* next;
    node(int k, int v, node* nxt){
        key = k;
        val = v;
        next = nxt;
    }
};

class MyHashMap {
public:
    const static int size = 10067;
    const static int multiplier = 1000253;
    
    node* table[size];
    
    int hash(int key){
        return (int)(((long)key*multiplier) %size);
    }
    
    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        node* tmp = new node(key, value, table[h]);
        table[h] = tmp;
    }
    
    int get(int key) {
        int h = hash(key);
        node* tmp = table[h];
        for(; tmp != NULL; tmp = tmp->next){
            if(tmp->key == key) return tmp->val;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        node* tmp = table[h];
        if(tmp == NULL) return;
        if(tmp->key == key) table[h] = tmp->next;
        else for(; tmp->next != NULL; tmp = tmp->next){
            if(tmp->next->key == key)
            {
                tmp->next = tmp->next->next;
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