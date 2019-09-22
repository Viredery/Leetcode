class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : hashSize(10000), hashSet(10000, nullptr)  {
        
    }
    
    void add(int key) {
        int idx = key % hashSize;
        if (hashSet[idx] == nullptr)
            hashSet[idx] = new ListNode(-1);
        ListNode* prev = findNodePrev(hashSet[idx], key);
        if (prev->next == nullptr)
            prev->next = new ListNode(key);
        else
            prev->next->key = key;
    }
    
    void remove(int key) {
        int idx = key % hashSize;
        if (hashSet[idx] == nullptr)
            return;
        ListNode* prev = findNodePrev(hashSet[idx], key);
        if (prev->next == nullptr)
            return;
        ListNode* node = prev->next;
        prev->next = node->next;
        delete node;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = key % hashSize;
        if (hashSet[idx] == nullptr)
            return false;
        ListNode* prev = findNodePrev(hashSet[idx], key);
        if (prev->next == nullptr)
            return false;
        return true;
    }
private:
    struct ListNode {
        int key;
        ListNode* next;
        ListNode(int k) : key(k), next(nullptr) {}
    };
    
    ListNode* findNodePrev(ListNode* node, int k) {
        while (node->next != nullptr && node->next->key != k)
            node = node->next;
        return node;
    }
    
    vector<ListNode*> hashSet;
    const int hashSize;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

