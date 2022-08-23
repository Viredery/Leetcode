/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        if (Iterator::hasNext()) {
	        next_value = std::make_optional(Iterator::next());
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return next_value.value();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    const int value = next_value.value();
        if (Iterator::hasNext()) {
            next_value = std::make_optional(Iterator::next());
        } else {
            next_value.reset();
        }
        return value;
	}
	
	bool hasNext() const {
	    return next_value.has_value();
	}
private:
    std::optional<int> next_value;
};
