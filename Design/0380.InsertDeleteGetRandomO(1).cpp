class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mapping.find(val) != mapping.end())
            return false;
        mapping[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mapping.find(val) == mapping.end())
            return false;

        int last = vec[vec.size() - 1];
        int idx = mapping[val];
        // move
        mapping[last] = idx;
        vec[idx] = last;
        // erase
        mapping.erase(mapping.find(val));
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % vec.size();
        return vec[idx];
    }
private:
    vector<int> vec;
    map<int, int> mapping;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
