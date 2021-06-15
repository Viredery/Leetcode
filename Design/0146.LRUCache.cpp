class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        if (dict_.find(key) == dict_.end()) {
            return -1;
        }
        std::list<std::pair<int, int>>::iterator iter = dict_[key];
        std::pair<int, int> key_value = *iter;
        cache_queue_.erase(iter);
        cache_queue_.push_front(key_value);
        dict_[key] = cache_queue_.begin();
        return key_value.second;
    }
    
    void put(int key, int value) {
        std::pair<int, int> key_value = {key, value};
        if (dict_.find(key) == dict_.end()) {
            cache_queue_.push_front(key_value);
            dict_[key] = cache_queue_.begin();
            if (cache_queue_.size() > capacity_) {
                dict_.erase(cache_queue_.back().first);
                cache_queue_.pop_back();
            }
            return;
        }
        cache_queue_.push_front(key_value);
        cache_queue_.erase(dict_[key]);
        dict_[key] = cache_queue_.begin();
    }
    
private:
    int capacity_ = 0;
    std::list<std::pair<int, int>> cache_queue_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> dict_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

