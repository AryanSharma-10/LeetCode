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
    void display(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void insertAtTail(ListNode *&head, int val)
{
    ListNode *n = new ListNode(val);
    ListNode *temp = head;

    if (head == NULL)
    {
        head = n;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(ListNode *&head, int val)
{
    ListNode *n = new ListNode(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    n->next = head;

    head = n;
}

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

ListNode* oddEvenList(ListNode* head)
{   
    int l=size(head);

    if(head==NULL || l==1 || l==2)
        return head;
    
    ListNode* odd=head;
    ListNode* i=odd;

    ListNode* even;
    ListNode* j;

    ListNode* nxt;

    int count=1;

    while(head->next!=NULL)
    {   
        nxt=head->next;
        if(count%2!=0)
        {
            if(head->next->next!=NULL)
            {   
                i->next=head->next->next;
                i=i->next;
            }
        }
        else
        {   
            if(count==2)
            {   
                even=head;
                j=even;
                if(head->next->next!=NULL)
                {   
                    j->next=head->next->next;
                    j=j->next;
                }
                else
                {   
                    j->next=NULL;
                }
            }

            else
            {
                if(head->next->next!=NULL)
                {   
                    j->next=head->next->next;
                    j=j->next;
                }
                else
                {   
                    j->next=NULL;
                }
            }
            
        }

        head=nxt;
        count++;
        
        cout<<endl;
    }
    
    i->next=even;

    return odd;
}
};