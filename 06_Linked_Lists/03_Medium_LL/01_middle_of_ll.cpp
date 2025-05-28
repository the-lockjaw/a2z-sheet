/*
876. Middle of the Linked List
Easy

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:
    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100
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

ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head, *slow = head;

    // first check if fast is nullptr before checking fast->next
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print_LL(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next; // IMPORTANT
    }
    cout << endl;
}

ListNode *vector_to_ll(vector<int> v)
{
    if (v.empty())
        return nullptr;

    // initialise w/ first value
    ListNode *head = new ListNode(v[0]);
    ListNode *temp = head;

    // iterate till end of vector
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
    vector<int> q = {1, 2, 3, 4, 5, 6};
    ListNode *head = vector_to_ll(q);
    ListNode *mid = middleNode(head);
    cout << "Middle node = " << mid->val << endl;
}