class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>::iterator p = nums.begin();
        int max = nums[0];
        vector<int>::iterator p_zero = find(p, nums.end(), 0);
        while(p_zero <= nums.end()) {
            if(p_zero != nums.end())
                max = bigger(max, 0);
            if(p != p_zero) {
                int count = count_if(p, p_zero, bind2nd(less<int>(), 0));
                if(count % 2 == 0) {
                    max = bigger(accumulate(p, p_zero, 1, multiplies<int>()), max);
                } else {
                    vector<int>::iterator a = find_if(p, p_zero, bind2nd(less<int>(), 0));
                    vector<int>::iterator b = find_if(static_cast<vector<int>::reverse_iterator>(p_zero),
                                    static_cast<vector<int>::reverse_iterator>(p), bind2nd(less<int>(), 0)).base() - 1;
                    if(a == b) {
                        max = bigger(*a, max);
                        if(a != p)
                            max = bigger(accumulate(p, a, 1, multiplies<int>()), max);
                        if(a + 1 != p_zero)
                            max = bigger(accumulate(a + 1, p_zero, 1, multiplies<int>()), max);
                    } else {
                        int tmp = accumulate(a + 1, b, 1, multiplies<int>());
                        max = bigger(tmp, max);
                        max = bigger(accumulate(p, a + 1, tmp, multiplies<int>()), max);
                        max = bigger(accumulate(b, p_zero, tmp, multiplies<int>()), max);
                    }
                }
                if(p_zero == nums.end())
                    break;
            }
            do {
            	p = p_zero + 1;
            	p_zero = find(p, nums.end(), 0);
	        }while(p == p_zero && p_zero != nums.end());
	        if(p_zero == nums.end() && p == p_zero)
		        break;
        }
        return max;
    }
    inline static int bigger(int a, int b) {
        return (a > b ? a : b);
    }
};
