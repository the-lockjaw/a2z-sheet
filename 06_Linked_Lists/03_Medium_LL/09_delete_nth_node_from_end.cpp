/*
19. Remove Nth Node From End of List
Medium
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz

Follow up: Could you do this in one pass?
*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *lead = head, *trail = head;
        while (n--)
            lead = lead->next;
        while (lead != nullptr)
        {
            trail = trail->next;
            lead = lead->next;
        }
        deleteNode(head, trail);
        return head;
    }

private:
    void deleteNode(ListNode *&head, ListNode *node)
    {
        if (head == nullptr || node == nullptr)
            return;

        if (head == node)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode *prev = head;
        while (prev->next != nullptr && prev->next != node)
        {
            prev = prev->next;
        }

        if (prev->next == node)
        {
            prev->next = node->next;
            delete node;
        }
    }
};