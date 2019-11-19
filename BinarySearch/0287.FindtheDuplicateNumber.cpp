class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l >> 1);
            int cnt = 0;
            for (int num : nums)
                if (num >= l && num <= mid)
                    cnt++;
            if (cnt > mid - l + 1)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
