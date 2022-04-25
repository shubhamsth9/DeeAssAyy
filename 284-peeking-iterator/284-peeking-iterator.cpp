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
    int i, n;
    vector<int> res;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    i = -1;
	    n = nums.size();
        for(int j=0; j<n; j++){
            res.push_back(nums[j]);
        }
        
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return res[i+1];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    i++;
        return res[i];
	}
	
	bool hasNext() const {
	    if(i < n-1) return true;
        return false;
	}
};