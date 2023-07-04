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
    ListNode* partition(ListNode* head, int x)
{   
    if(head==NULL)
        return NULL;

    ListNode* lesser=new ListNode(999);
    ListNode* j=lesser;

    ListNode* greater=new ListNode(999);
    ListNode* i=greater;


    while(head!=NULL)
    {
        if(head->val<x)
        {   
            if(j->val==999)
            {   
                j->val=head->val;
            }
            else
            {   
                cout<<"Adding to lesser: "<<head->val<<endl;
                ListNode* temp=new ListNode(head->val);
                j->next=temp;
                j=temp;
            }
        }

        else
        {
            if(i->val==999)
            {
                i->val=head->val;
            }
            else
            {
                ListNode* temp=new ListNode(head->val);
                i->next=temp;
                i=i->next;
            }
        }

        head=head->next;
    }

    if(i->val==999)
        return lesser;
    
    if(j->val==999)
        return greater;

    j->next=greater;
    return lesser;
}
};