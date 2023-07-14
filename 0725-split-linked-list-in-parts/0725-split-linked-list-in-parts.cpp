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

vector<ListNode *> splitListToParts(ListNode *head, int k)
{   
    vector<ListNode *> result;

    if(k==1)
    {
        result.push_back(head);
        return result;
    }

    int length = size(head);

    if (k >= length)
    {
        ListNode *curr = head;
        ListNode *next;
        while (k > 0)
        {
            if (curr == NULL)
            {
                result.push_back(curr);
                k--;
            }
            else
            {
                next = curr->next;
                curr->next = NULL;
                result.push_back(curr);
                curr = next;
                k--;
            }
        }
    }
    else
    {
        int count = length / k;
        int extra = length % k;

        ListNode *curr = head;
        ListNode *end = head;
        ListNode *next;

        while (k > 0)
        {
            end = curr;
            for (int i = 0; i < count - 1; i++)
            {
                end = end->next;
            }

            if (extra)
            {
                end = end->next;
                extra--;
            }
            next = end->next;

            end->next = NULL;
            result.push_back(curr);
            curr = next;
            k--;
        }
    }
    
    return result;
}
};