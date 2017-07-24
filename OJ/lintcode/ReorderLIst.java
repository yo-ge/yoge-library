/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param head: The head of linked list.
     * @return: void
     */
    public void reorderList(ListNode head) {  
        // write your code here
        if (head == null || head.next == null 
            || head.next.next == null)
            return;
        ListNode slow, fast;
        slow = fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        } 
        ListNode head2 = slow.next;
        slow.next = null;
        head2 = reverseList(head2);
        /* Merges two lists. */
        while (head2 != null) {
            ListNode next1 = head.next;
            head.next = head2;
            head2 = head2.next;
            head = head.next;
            head.next = next1;
            head = head.next;
        }
    }
    
    private ListNode reverseList(ListNode head) {
        if (head == null) return null;
        ListNode reversedHead = null;
        ListNode next = null;
        while (head != null) {
            next = head.next;
            head.next = reversedHead;
            reversedHead = head;
            head = next;
        }
        return reversedHead;
    }
}
