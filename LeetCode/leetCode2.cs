/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        
        int carry = 0;
        ListNode head = new ListNode(), tail = null;

        while (l1 != null || l2 != null) {
            ListNode temp = new ListNode();
            
            if (l1 != null && l2 != null) {
                temp.val = (l1.val + l2.val + carry) % 10;
                carry = ((l1.val + l2.val + carry >= 10) ? 1 : 0);

                l1 = l1.next;
                l2 = l2.next;
            }
            else if (l1 == null && l2 != null) {
                temp.val = (l2.val + carry) % 10;
                carry = ((l2.val + carry >= 10) ? 1 : 0);
                l2 = l2.next;
            }
            else {
                temp.val = (l1.val + carry) % 10;
                carry = ((l1.val + carry >= 10) ? 1 : 0);
                l1 = l1.next;
            }

            if (tail == null)
            {
                tail = new ListNode();
                tail = temp;
                head = tail;
            }
            else 
            {
                tail.next = temp;
                tail = temp;
            }

        }

        if (carry == 1)
        {
            ListNode temp = new ListNode(1, null);
            tail.next = temp;
        }

        return head;
    }
}