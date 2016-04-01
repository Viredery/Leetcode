class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> set_int;
        vector<int>::iterator p = nums.begin(), end = nums.end();
        while(p != end) {
            int num = *p;
            if(set_int.count(num) == 0)
                set_int.insert(num);
            else
                set_int.erase(num);
            p++;
        }
        return *(set_int.begin());
    }
};
