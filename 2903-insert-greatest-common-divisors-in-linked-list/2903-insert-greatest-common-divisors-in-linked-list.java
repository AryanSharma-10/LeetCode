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
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if(head.next==null)
            return head;

        ListNode curr=head;

        while(curr.next!=null)
        {
            int n=gcd(curr.val, curr.next.val);
            System.out.println(n);
            ListNode temp=new ListNode(n, curr.next);
            curr.next=temp;
            curr=temp.next;
        }
        
        return head;
    }

    public static int gcd(int n1, int n2)
    {
         int gcd = 1;

        for (int i = 1; i <= n1 && i <= n2; ++i) {
            if (n1 % i == 0 && n2 % i == 0)
                gcd = i;
        }

        return gcd;
    }
}