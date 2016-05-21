public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        List<Integer> list = new ArrayList<Integer>();
        for (int num : nums1) {
            if (map.containsKey(num))
                map.put(num, map.get(num) + 1);
            else
                map.put(num, 1);
        }
        for (int num : nums2) {
            if (map.containsKey(num)) {
                list.add(num);
                if (map.get(num) == 1)
                    map.remove(num);
                else
                    map.put(num, map.get(num) - 1);
            }
        }
        int[] result = new int[list.size()];
        for (int i = 0; i != list.size(); i++)
            result[i] = list.get(i);
        return result;
    }
}