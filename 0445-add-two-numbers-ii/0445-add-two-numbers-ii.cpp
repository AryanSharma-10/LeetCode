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

    ListNode* i=head;
    ListNode* prev=head;
    ListNode* inext;
    while(i->next!=NULL)
    {   
        inext=i->next;
        if(i==head)
        {
            i->next=NULL;
            prev=head;
        }
        else
        {
            i->next=prev;
            prev=i;
        }
        i=inext;
    }

    i->next=prev;

    return i;
}

ListNode* addTwoNumbers(ListNode* A, ListNode* B)
{ 
    A=reverse(A);
    B=reverse(B);
    // display(A);
    // display(B);
    ListNode* result=NULL;
    ListNode* prev;
    
    int carry=0;
    int sum=0;

    while(A!=NULL && B!=NULL)
    {   
        sum=A->val+B->val+carry;

        if(sum>9)
        {
            sum%=10;
            carry=1;
        }
        else
            carry=0;

        if(result==NULL)
        {
            ListNode* temp=new ListNode(sum,NULL);
            result=temp;
            prev=result;
        }
        else
        {
            ListNode* temp=new ListNode(sum,NULL);
            prev->next=temp;
            prev=temp;
        }
        
        A=A->next;
        B=B->next;

    }
    cout<<endl;

    while(A!=NULL)
    {
        sum=A->val+carry;  

        if(sum>9)
        {
            sum%=10;
            carry=1;
        }
        else
            carry=0;

        ListNode* temp=new ListNode(sum,NULL);
        prev->next=temp;
        prev=temp;

        A=A->next;
    }

    while(B!=NULL)
    {
        sum=B->val+carry;  

        if(sum>9)
        {
            sum%=10;
            carry=1;
        }
        else
            carry=0;

        ListNode* temp=new ListNode(sum,NULL);
        prev->next=temp;
        prev=temp;

        B=B->next;
    }

    if(carry==1)
    {   
        ListNode* t=new ListNode(1,NULL);
        prev->next=t;
    }

    return reverse(result);
}
};