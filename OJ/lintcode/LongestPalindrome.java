import java.util.HashSet;

public class LongestPalindrome {
    /**
     * @param s a string which consists of lowercase or uppercase letters
     * @return the length of the longest palindromes that can be built
     */
    public int longestPalindrome(String s) {
        // Write your code here
        HashSet<Character> set = new HashSet<Character>();
        if (s.length() < 2) return s.length();
        int ans = 0;
        for (Character ch : s.toCharArray()) {
            if (set.contains(ch)) {
                set.remove(ch);
                ans += 2;
            } else {
                set.add(ch);
            }
        }
        return set.isEmpty() ? ans : ans + 1;
    }

    public static void main(String args[]) {
        LongestPalindrome longestPalindrome = new LongestPalindrome();
        System.out.println(longestPalindrome.longestPalindrome("daaacccc"));
    }
}