#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int lenght_of_loop(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        bool is_cycle = false;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                is_cycle = true;
                break;
            }
        }
        if (!is_cycle)
            return 0;
        int length = 0;
        // honestly how could i not think of this??
        do
        {
            fast = fast->next;
            length++;
        } while (fast != slow);
        return length;
    }
};
