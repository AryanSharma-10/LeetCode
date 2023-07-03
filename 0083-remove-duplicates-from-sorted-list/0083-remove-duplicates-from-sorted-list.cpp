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
    void display(ListNode* head)
    {
        while(head!=NULL)
        {
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;

        ListNode* i=head;
        
        while(i->next!=NULL)
        {   
            ListNode* j=i->next;
            display(head);

            while(j!=NULL && i->val==j->val)
            {   
                j=j->next;
            }

            i->next=j;

            if(j!=NULL)
                i=j;

        }

        return head;
    }
};