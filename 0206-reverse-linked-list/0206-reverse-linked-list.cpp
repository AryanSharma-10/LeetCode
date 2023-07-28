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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
    ListNode* i=head;
    ListNode* prev;
    
    while(i->next!=NULL)
    {   
        if(i==head)
        {   
            prev=i;
            i=i->next;
            prev->next=NULL;
        }
        else
        {
            ListNode* inext=i->next;
            i->next=prev;
            prev=i;
            i=inext;
        }
        
    }

    i->next=prev;

    return i;    
    }
};