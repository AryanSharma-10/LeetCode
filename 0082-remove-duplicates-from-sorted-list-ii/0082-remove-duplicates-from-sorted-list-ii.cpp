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
    ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* i=head;
    ListNode* prev=i;
    
    while(i!=NULL && i->next!=NULL)
    {   
        ListNode* j=i->next;
        while(j!=NULL && i->val==j->val)
        {
            j=j->next;
        }
        
        if(j!=i->next)
        {   
            if(i==head)
            {
                head=j;
                i=j;
            }
            else
            {
                prev->next=j;
                i=j;
            }
        }
        else
        {
            prev=i;
            i=j;
        }
        
    }

    return head;
}
};