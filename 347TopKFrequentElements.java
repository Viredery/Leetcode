public class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> dict = new HashMap<Integer, Integer>();
        for (int num : nums) {
            if (!dict.containsKey(num))
                dict.put(num, 1);
            else
                dict.put(num, dict.get(num) + 1);
        }
        List<Map.Entry<Integer, Integer>> mapping = 
            new ArrayList<Map.Entry<Integer, Integer>>(dict.entrySet());
        Collections.sort(mapping, new Comparator<Map.Entry<Integer, Integer>>() {
            public int compare(Map.Entry<Integer, Integer> leftMapping, 
                               Map.Entry<Integer, Integer> rightMapping) {
                return rightMapping.getValue() - leftMapping.getValue();
            }
        });
        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i != k; i++) {
            result.add(mapping.get(i).getKey());
        }
        return result;
    }
}