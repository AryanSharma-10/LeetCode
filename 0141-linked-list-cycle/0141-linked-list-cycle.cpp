/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(head==NULL)
        return NULL;
        
    int n = 999999;
    ListNode* i=head->next;
    head->val=n;
    
    while(i!=NULL)
    {   
        if(i->next!=NULL && i->next->val==n)
            return true;
        i->val=n;
        i=i->next;
    }

    return false; 
    }
};