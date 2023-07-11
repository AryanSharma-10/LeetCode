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
ListNode* reverse(ListNode* head)
{   
    if(head==NULL || head->next==NULL)
        return head;
    ListNode* curr=head;
    ListNode* next=NULL;
    ListNode* prev;

    while(curr->next!=NULL)
    {   
        ListNode* next=curr->next;
        if(curr==head)
        {
            curr->next=NULL;
            prev=curr;
        }
        else
        {
            curr->next=prev;
            prev=curr;
        }
        curr=next;
    }
    curr->next=prev;
    return curr;
}

ListNode* removeNodes(ListNode* head) 
{   
    if(head==NULL || head->next==NULL)
        return head;

    head=reverse(head);
    ListNode* curr=head->next;
    ListNode* prev=head;
    int maxNode=head->val;
    
    while(curr!=NULL)
    {   
        if(maxNode<=curr->val)
        {   
            maxNode=curr->val;
            prev->next=curr;
            prev=curr;
        }

        curr=curr->next;
    }
    prev->next=NULL;

    return reverse(head);
} 
};