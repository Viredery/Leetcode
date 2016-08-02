public class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>(
            new Comparator<int[]>() {
                public int compare(int[] o1, int[] o2) {
                    return o1[0] < o2[0] ? -1 : (o1[0] == o2[0] ? 0 : 1);
                }
            });
        for (int i = 0; i != matrix.length; i++) {
            pq.offer(new int[]{matrix[0][i], 0, i});
        }
        int[] curr = new int[3];
        for (int i = 0; i != k; i++) {
            curr = pq.poll();
            int row = curr[1], col = curr[2];
            if (row + 1 != matrix.length)
                pq.offer(new int[]{matrix[row + 1][col], row + 1, col});
        }
        return curr[0];
    }
}