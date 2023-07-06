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
 ListNode* specialReverse(ListNode* head, ListNode* remaining)
{   
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

ListNode* reverseKGroup(ListNode* head, int k) 
{   
    if(head==NULL || head->next==NULL || k==1)
        return head;

    ListNode* i=head;
    ListNode* j=NULL;
    ListNode* prev=NULL;
    ListNode* remaining=i;

    int count=1;
    bool flag=true;
    bool s=true;
    while(flag && i!=NULL)
    {   
        i=remaining;
        for(int x=0;x<k;x++)
        {   
            if(x==0)
                prev=remaining;

            remaining=remaining->next;
            if(remaining==NULL && x!=k-1)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {   
            i=specialReverse(i, remaining);
            
            if(s)
            {   
                j=head;
                head=i;
            }
            else
            {
                j->next=i;
                j=prev;
            }

        }
        i=remaining;
        s=false;
    }
    return head;
}
};