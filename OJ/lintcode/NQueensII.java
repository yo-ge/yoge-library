public class NQueensII {
    class Solution {
        
        private int count;

        /**
         * Calculate the total number of distinct N-Queen solutions.
         * @param n: The number of queens.
         * @return: The total number of distinct solutions.
         */
        public int totalNQueens(int n) {
            //write your code here
            int[] q = new int[n];
            count = 0;
            totalNQueensHelper(q, 0);
            return count;
        }

        private void printQueens(int[] q) {
            for (int pos : q) {
                System.out.print(pos);
            }
            System.out.println();
        }

        private void totalNQueensHelper(int[] q, int k) {
            int n = q.length;
            if (k == n) {
                ++count; 
                // printQueens(q);
                return;
            }
            for (int i = 0; i < n; ++i) {
                q[k] = i;
                if (isConsistent(q, k)) {
                    totalNQueensHelper(q, k + 1);
                }
            }
        }

        private boolean isConsistent(int[] q, int n) {
            for (int i = 0; i < n; ++i) {
                if (q[i] - q[n] == n - i || q[n] - q[i] == n - i
                    || q[i] == q[n]) {
                    return false;
                }
            }
            return true;
        }
    }

    /* Tests. */
    // public static void main(String[] args) {
    //     NQueensII nqueens = new NQueensII();
    //     for (int i = 0; i < 11; ++i) {
    //         NQueensII.Solution solution = nqueens.new Solution();
    //         System.out.println(i + ": " + solution.totalNQueens(i));
    //     }
    // }
}