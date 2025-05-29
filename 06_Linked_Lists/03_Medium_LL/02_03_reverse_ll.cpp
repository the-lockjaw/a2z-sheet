/*
206. Reverse Linked List
Easy

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
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

ListNode *reverseListRecursive(ListNode *head)
{
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Recursively reverse the rest of the list
    ListNode *newHead = reverseListRecursive(head->next);

    // Reverse the current node's pointer
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

void print_LL(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *vector_to_ll(vector<int> v)
{
    if (v.empty())
        return nullptr;

    ListNode *head = new ListNode(v[0]);
    ListNode *temp = head;

    for (int i = 1; i < v.size(); i++)
    {
        ListNode *new_node = new ListNode(v[i]);
        temp->next = new_node;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    ListNode *head = vector_to_ll(a);
    cout << "Before reversal : " << endl;
    print_LL(head);

    ListNode *rev = reverseList(head);
    cout << "After reversal : " << endl;
    print_LL(rev);

    ListNode *rev2 = reverseListRecursive(rev);
    cout << "After reversal (recursive) : " << endl;
    print_LL(rev2);
}