/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* i=head;
        ListNode* prev;

        while(i!=NULL && i->next!=NULL)
        {   
            ListNode* j=i->next;
            if(i==head)
            {
                i->next=j->next;
                j->next=i;
                head=j;
            }
            else
            {
                prev->next=j;
                i->next=j->next;
                j->next=i;
            }

            prev=i;
            i=i->next;
        }

        return head;
    }

};