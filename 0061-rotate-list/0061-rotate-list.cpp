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
    int size(ListNode *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

ListNode *rotateRight(ListNode *head, int k)
{   
    if(head==NULL)
        return head;
    int i = 0;
    int l=size(head);
    ListNode* curr=head;
    while((i+k)%l!=0)
    {
        curr=curr->next;
        i++;
    }

    ListNode* start=curr;
    
    ListNode* rotatedList=new ListNode(curr->val);
    ListNode* tail=rotatedList;
    curr=curr->next;

    while(curr!=NULL)
    {
        ListNode* temp=new ListNode(curr->val);
        tail->next=temp;
        tail=tail->next;
        curr=curr->next;
    }

    curr=head;
    while(curr!=start)
    {
        ListNode* temp=new ListNode(curr->val);
        tail->next=temp;
        tail=tail->next;
        curr=curr->next;
    }

    return rotatedList;
}
};