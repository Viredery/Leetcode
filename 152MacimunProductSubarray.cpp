class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>::iterator p = nums.begin();
        int max = nums[0];
        vector<int>::iterator p_zero = find(p, nums.end(), 0);
        while(p_zero <= nums.end()) {
            if(p_zero != nums.end())
                max = bigger(max, 0);
            int count = count_if(p, p_zero, isnegative);
            if(count % 2 == 0) {
                max = bigger(accumulate_multi(p, p_zero, 1), max);
            } else {
                vector<int>::iterator a = find_if_foward(p, p_zero);
                vector<int>::iterator b = find_if_reserse(p, p_zero);
                if(a == b) {
                    max = bigger(*a, max);
                    max = bigger(accumulate_multi(p, a, 1), max);
                    max = bigger(accumulate_multi(a + 1, p_zero, 1), max);
                } else {
                    int tmp = accumulate_multi(a + 1, b, 1);
                    max = bigger(tmp, max);
                    max = bigger(accumulate_multi(p, a + 1, tmp), max);
                    max = bigger(accumulate_multi(b, p_zero, tmp), max);
                }
            }
            if(p_zero == nums.end())
                break;
            do {
            	p = p_zero + 1;
            	p_zero = find(p, nums.end(), 0);
	        }while(p == p_zero && p_zero != nums.end());
	        if(p_zero == nums.end() && p == p_zero)
		        break;
        }
        return max;
    }
    static int bigger(int a, int b) {
        return (a > b ? a : b);
    }
    static bool isnegative(int a) {
        return (a < 0);
    }
    static int multi(int a, int b) {
        return a * b;
    }
    vector<int>::iterator find_if_foward(vector<int>::iterator a, vector<int>::iterator b) {
        while(a != b) {
            if(*a < 0)
                return a;
            a++;
        }
        return b;
    }
    vector<int>::iterator find_if_reserse(vector<int>::iterator a, vector<int>::iterator b) {
        b--;
        while(b != a) {
            if(*b < 0)
                return b;
            b--;
        }
        return a;
    }
    int accumulate_multi(vector<int>::iterator a, vector<int>::iterator b, int start) {
	    if(a == b) {
	        if(start == 1)
	            return INT_MIN;
            else 
                return start;
	    }
        while(a != b) {
            start *= (*a);
            a++;
        }
	    return start;
    }
};
