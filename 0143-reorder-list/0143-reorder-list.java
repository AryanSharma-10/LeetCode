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
    public void reorderList(ListNode head) {
        
        Stack<ListNode> stack = new Stack<>();
        ListNode i = head;
        int count = 0;
        while(i!=null)
        {
            stack.push(i);
            i = i.next;
            count++;
        }

        i = head;
        System.out.println(count);
        int c=0;
        while(c<count/2)
        {   
            ListNode inext=i.next;
            i.next = stack.pop();
            i.next.next = inext;
            i=inext;
            c++;
        }

        i.next=null;
    }   
}