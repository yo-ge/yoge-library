public class Solution {
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    public int maxSquare(int[][] matrix) {
        // write your code here
        if (matrix == null) return 0;
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[][] dp = new int[rows][cols];
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            dp[i][0] = matrix[i][0];
            if (dp[i][0] == 1) {
                ans = 1;
            }
        }
        for (int j = 0; j < cols; ++j) {
            dp[0][j] = matrix[0][j];
            if (dp[0][j] == 1) {
                ans = 1;
            }
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], 
                    Math.min(dp[i - 1][j - 1], dp[i][j - 1]));
                } else {
                    dp[i][j] = 0;
                }
                ans = Math.max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
}