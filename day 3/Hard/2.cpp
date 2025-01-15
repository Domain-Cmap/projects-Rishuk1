#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *curr = head;

        int count = 0;
        while (curr)
        {
            count++;
            curr = curr->next;
        }

        while (count >= k)
        {
            curr = prev->next;
            ListNode *next = curr->next;

            for (int i = 1; i < k; i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            prev = curr;
            count -= k;
        }

        return dummy.next;
    }
};