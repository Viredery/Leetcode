class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        smallerNums = vector<int>(nums.size(), 0);
        indices = vector<int>(nums.size(), 0);
        iota(indices.begin(), indices.end(), 0);
        
        mergeSort(nums, 0, nums.size()-1);
        
        return smallerNums;
    }
    
private:
    vector<int> smallerNums;
    vector<int> indices;
    
    void merge(vector<int>& nums, int left, int right, int mid) {
        vector<int> tmp(right-left+1, 0);
        int i = left, j = mid+1, k = 0;
        while (i <= mid && j <= right) {
            if (nums[indices[i]] > nums[indices[j]]) {
                tmp[k++] = indices[i];
                smallerNums[indices[i]] += right - j + 1;
                i++;
            } else {
                tmp[k++] = indices[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = indices[i++];
        }
        while (j <= right) {
            tmp[k++] = indices[j++];
        }
        move(tmp.begin(), tmp.end(), indices.begin()+left);
        
    }
    
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, right, mid);
    }
};
