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
class Stack
{
    public:
    ListNode* val;
    Stack* next;

    Stack()
    {
        val=NULL;
        next=NULL;
    }

    Stack(ListNode* node)
    {
        val=node;
        next=NULL;
    }

    Stack(ListNode* node, Stack* n)
    {
        val=node;
        next=n;
    }
};

ListNode* pop(Stack*& top)
{
    if(top==NULL)
        return NULL;
    
    ListNode* t=top->val;
    top=top->next;

    return t;
}

void push(Stack*& top, ListNode* node)
{
    Stack* t=new Stack(node);
    if(top==NULL)
    {
        top=t;
    }
    else
    {
        t->next=top;
        top=t;
    }
}

void display(Stack* top)
{
    while(top!=NULL)
    {
        cout<<top->val->val<<endl;
        top=top->next;
    }
    cout<<"NULL"<<endl;
}

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

    int pairSum(ListNode* head) {
        Stack* top=NULL;
        int length=size(head);
        ListNode* curr=head;

        for(int i=0;i<length/2;i++)
        {   
            push(top,curr);
            curr=curr->next;
        }

        int maxSum=0;
        while(curr!=NULL)
        {   
            int sum=pop(top)->val+curr->val;
            maxSum=max(maxSum, sum);
            curr=curr->next;
        }
        
        return maxSum;
    }

};