/*
234. Palindrome Linked List
Easy

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
    The number of nodes in the list is in the range [1, 1e5].
    0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }

        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *second = revLL(slow);
        ListNode *first = head;

        while (second != nullptr && first != nullptr)
        {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }

private:
    ListNode *revLL(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *temp = head, *prev = nullptr;
        while (temp != nullptr)
        {
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
};