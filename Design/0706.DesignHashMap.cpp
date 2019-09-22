class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : hashSize(10000), hashMap(10000, nullptr) {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key % hashSize;
        if (hashMap[idx] == nullptr)
            hashMap[idx] = new ListNode(-1, -1);
        ListNode* prev = findNodePrev(hashMap[idx], key);
        if (prev->next == nullptr)
            prev->next = new ListNode(key, value);
        else
            prev->next->val = value;
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key % hashSize;
        if (hashMap[idx] == nullptr)
            return -1;
        ListNode* prev = findNodePrev(hashMap[idx], key);
        if (prev->next == nullptr)
            return -1;
        return prev->next->val;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = key % hashSize;
        if (hashMap[idx] == nullptr)
            return;
        ListNode* prev = findNodePrev(hashMap[idx], key);
        if (prev->next == nullptr)
            return;
        ListNode* node = prev->next;
        prev->next = node->next;
        delete node;
    }
private:
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode(int k, int v) : key(k), val(v), next(nullptr) {}
    };
    
    ListNode* findNodePrev(ListNode* node, int k) {
        while (node->next != nullptr && node->next->key != k)
            node = node->next;
        return node;
    }
    
    vector<ListNode*> hashMap;
    const int hashSize;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
