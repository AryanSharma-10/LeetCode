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

ListNode* specialReverse(ListNode* head, ListNode* remaining)
{   
    if(head==NULL || head->next==NULL)
        return head;

    ListNode* i=head;
    ListNode* prev;
    
    while(i->next!=remaining)
    {   
        if(i==head)
        {   
            prev=i;
            i=i->next;
            prev->next=remaining;
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

ListNode* reverseBetween(ListNode* head, int left, int right)
{   
    cout<<"left: "<<left<<endl;
    cout<<"right: "<<right<<endl;
    if(head->next==NULL || left==right)
        return head;
    
    ListNode* i=head;
    ListNode* j=NULL;
    ListNode* remaning=i;

    int length=size(head);

    int count=1;
    while(count<left)
    {   
        j=i;
        i=i->next;
        remaning=i;
        count++;
    }

    while(remaning!=NULL && count<=right)
    {
        remaning=remaning->next;
        count++;
    }
    i=specialReverse(i,remaning);
    if(j==NULL)
    {
        head=i;
    }
    else
        j->next=i;

    return head;
}
};