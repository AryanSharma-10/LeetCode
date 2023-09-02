/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    static int carry;
    public ListNode doubleIt(ListNode head) {
        carry=0;
        doubleLL(head);
        if(carry==1)
        {
            ListNode newHead = new ListNode(1, head);
            return newHead;
        }

        return head;
    }

    public static void doubleLL(ListNode head)
    {
        if(head.next!=null)
            doubleLL(head.next);
        
        int num=head.val*2+carry;
        head.val=num%10;
        carry=num/10;
    }
}