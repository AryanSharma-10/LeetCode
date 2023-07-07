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
    ListNode* mergeNodes(ListNode* head)
{   
    ListNode *result=NULL;
    ListNode* j=head;
    ListNode* i=head->next;

    while(i!=NULL)
    {   
        int sum=0;
        while(i->val!=0)
        {
            sum+=i->val;
            i=i->next;
        }

        if(result==NULL)
        {
            ListNode* t=new ListNode(sum,NULL);
            result=t;
            j=result;
        }
        else
        {
            ListNode* t=new ListNode(sum,NULL);
            j->next=t;
            j=t;
        }

        i=i->next;
    }

    return result;
}
};