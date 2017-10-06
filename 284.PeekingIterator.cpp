class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        next_ptr = &next_val;
        if (Iterator::hasNext())
	        next_val = Iterator::next();
        else
            next_ptr = nullptr;
            
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return *next_ptr;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int res = *next_ptr;
        if (Iterator::hasNext())
	        next_val = Iterator::next();  
        else
            next_ptr = nullptr;
        return res;
	}

	bool hasNext() const {
	    return next_ptr;
	}
private:
    int *next_ptr;
    int next_val;
};