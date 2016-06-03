public class NumArray {

    public NumArray(int[] nums) {
        sum = new int[nums.length + 1];
        int total = 0;
        sum[0] = 0;
        for (int i = 0; i != nums.length; i++) {
            total += nums[i];
            sum[i + 1] = total;
        }
    }

    public int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
    
    private int[] sum;
    
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);