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
    void deleteNode(ListNode* node) {
        int data;
        ListNode* prev;
        while(node->next!=NULL)
        {   
            node->val=node->next->val;
            prev=node;
            node=node->next;

            if(node->next==NULL)
                prev->next=NULL;
        }
        
    }
};