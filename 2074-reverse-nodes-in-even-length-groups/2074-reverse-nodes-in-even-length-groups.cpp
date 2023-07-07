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
ListNode *specialReverse(ListNode *head, ListNode *remaining)
{   
    ListNode *prev = NULL;
    ListNode *i = head;
    ListNode *result;
    while (i != remaining)
    {
        ListNode *inext = i->next;

        if (i == head)
        {
            i->next = remaining;
            prev = i;
        }
        else
        {
            i->next = prev;
            prev = i;
        }
        result = i;
        i = inext;
    }
    return result;
}

ListNode *reverseEvenLengthGroups(ListNode *head)
{

    if (head->next == NULL || head->next->next == NULL)
        return head;

    ListNode *start = head;
    ListNode *p = head->next;
    ListNode *end = head;
    ListNode *t;

    int count = 2;

    ListNode *startnxt = start;
    bool flag=false;
    int i;
    while (p != NULL)
    {
        startnxt = start->next;
        for (i = 0; i < count; i++)
        {
            if(count%2!=0)
                start=p;

            p = p->next;
            if (p == NULL)
            {   
                if(i%2!=0 && count%2!=0)
                {
                    start=t;
                    flag=true;
                }

                break;
            }
        }
        

        if((count%2==0 && p!=NULL) || (p==NULL && flag) || (p==NULL && i%2!=0))
        {   
            start->next = specialReverse(start->next, p);
            start = startnxt;
            t=start;
        }
        
        count++;
    }

    return head;
}

};