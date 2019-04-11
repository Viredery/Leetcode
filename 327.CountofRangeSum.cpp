class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size()+1, 0);
        for (int i = 0; i != nums.size(); i++)
            sums[i+1] = sums[i] + nums[i];
        return countRange(sums, 0, nums.size()+1, lower, upper);
    }
private:
    int countRange(vector<long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1)
            return 0;
        int mid = start + (end - start) / 2;
        long count = countRange(sums, start, mid, lower, upper) + countRange(sums, mid, end, lower, upper);
        int r = mid, l = mid;
        for (int i = start; i != mid; i++) {
            while (l < end && sums[l] - sums[i] < lower)
                l++;
            while (r < end && sums[r] - sums[i] <= upper)
                r++;
            count += r - l;
        }
        inplace_merge(sums.begin()+start, sums.begin()+mid, sums.begin()+end);
        return count;
    }
};
