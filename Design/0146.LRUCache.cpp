
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        if (mapped.find(key) == mapped.end())
            return -1;
        list<Node>::iterator iter = mapped[key];
        Node node = *iter;
        int val = node.get();
        
        cached.erase(iter);
        cached.push_front(node);
        mapped[key] = cached.begin();
        
        return val;
    }
    
    void put(int key, int value) {
        if (mapped.find(key) != mapped.end()) {
            list<Node>::iterator iter = mapped[key];
            Node node = *iter;
            node.set(value);
            
            cached.erase(iter);
            cached.push_front(node);
            mapped[key] = cached.begin();
            return;
        }
        if (cached.size() == capacity) {
            int key = cached.back().getKey();
            cached.pop_back();
            mapped.erase(key);
        }
        Node node(key, value);
        cached.push_front(node);
        mapped[key] = cached.begin();
    }
private:
    struct Node {
        int key;
        int val;
        Node(int k, int v) : key(k), val(v) {}
        void set(int v) { val = v; }
        int get() { return val; }
        int getKey() { return key; }
        
    };
    list<Node> cached;
    unordered_map<int, list<Node>::iterator> mapped;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
