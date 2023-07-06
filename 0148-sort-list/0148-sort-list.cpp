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
    ListNode *merge(ListNode *A, ListNode *B)
{
    ListNode *i = A;
    ListNode *j = B;
    ListNode *result = NULL;
    ListNode *k;

    while (i != NULL && j != NULL)
    {
        if (i->val > j->val)
        {
            if (result == NULL)
            {
                result = j;
                k = result;
                j = j->next;
            }
            else
            {
                k->next = j;
                j = j->next;
                k = k->next;
            }
        }
        else
        {
            if (result == NULL)
            {
                result = i;
                k = result;
                i = i->next;
            }
            else
            {
                k->next = i;
                i = i->next;
                k = k->next;
            }
        }
    }

    while (i != NULL)
    {
        k->next = i;
        i = i->next;
        k = k->next;
    }

    while (j != NULL)
    {
        k->next = j;
        j = j->next;
        k = k->next;
    }

    return result;
}

ListNode *sortList(ListNode *list)
{
    int length = size(list);
    if (length <= 1)
    {
        return list;
    }

    ListNode *sorted = list;

    ListNode *A;
    ListNode *B;

    ListNode *i;
    ListNode *j;

    int c = 1;
    A = list;
    i = A;
    list = list->next;
    while (c < length / 2)
    {
        i->next = list;
        i = i->next;
        list = list->next;
        c++;
    }

    B = list;
    j = B;
    list = list->next;
    while (list != NULL)
    {
        j->next = list;
        j = j->next;
        list = list->next;
    }
    i->next = NULL;

    A = sortList(A);
    B = sortList(B);
    list = merge(A, B);

    return list;
}
};