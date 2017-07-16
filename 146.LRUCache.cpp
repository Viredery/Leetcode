class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity), count_(0) {
        head_ = new DLinkedNode(0, 0);
        tail_ = new DLinkedNode(0, 0);
        head_->post_ = tail_;
        tail_->pre_ = head_;
    }
    
    int get(int key) {
        auto iter = cache_.find(key);
        if (iter == cache_.end())
            return -1;
        auto node = iter->second;
        moveToHead(node);
        return node->value_;
    }
    
    void put(int key, int value) {
        auto iter = cache_.find(key);
        if (iter == cache_.end()) {
            DLinkedNode* node = new DLinkedNode(key, value);
            if (count_ >= capacity_) {
                DLinkedNode* dlt = popTail();
                cache_.erase(dlt->key_);
            } else 
                count_++;
            add(node);
            cache_[key] = node;
        } else {
            auto node = iter->second;
            node->value_ = value;
            moveToHead(node);
        }
    }
private:
    class DLinkedNode {
    public:
        DLinkedNode(int key, int value) : key_(key), value_(value), pre_(nullptr), post_(nullptr) {}
        int key_;
        int value_;
        DLinkedNode* pre_;
        DLinkedNode* post_;
    };
    DLinkedNode* head_;
    DLinkedNode* tail_;
    unordered_map<int, DLinkedNode*> cache_;
    int capacity_;
    int count_;
    
    void moveToHead(DLinkedNode* node) {
        remove(node);
        add(node);
    }
    DLinkedNode* popTail() {
        DLinkedNode* node = tail_->pre_;
        remove(node);
        return node;
    }
    void remove(DLinkedNode* node) {
        node->pre_->post_ = node->post_;
        node->post_->pre_ = node->pre_;
    }
    void add(DLinkedNode* node) {
        node->post_ = head_->post_;
        node->pre_ = head_;
        head_->post_->pre_ = node;
        head_->post_ = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */