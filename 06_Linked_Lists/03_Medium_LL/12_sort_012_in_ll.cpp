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

void sort(ListNode *&head)
{
    // counting sort
    // OR
    // three separate lists for 0s, 1s and 2s and then merge
}

/*
Node* sort012List(Node* head) {
    if (!head || !head->next) return head;

    Node *zeroHead = nullptr, *zeroTail = nullptr;
    Node *oneHead = nullptr, *oneTail = nullptr;
    Node *twoHead = nullptr, *twoTail = nullptr;

    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;
        curr->next = nullptr;

        if (curr->data == 0) {
            if (!zeroHead) zeroHead = zeroTail = curr;
            else zeroTail = zeroTail->next = curr;
        } else if (curr->data == 1) {
            if (!oneHead) oneHead = oneTail = curr;
            else oneTail = oneTail->next = curr;
        } else {
            if (!twoHead) twoHead = twoTail = curr;
            else twoTail = twoTail->next = curr;
        }

        curr = nextNode;
    }

    // Connect the sublists
    if (zeroTail) zeroTail->next = oneHead ? oneHead : twoHead;
    if (oneTail) oneTail->next = twoHead;

    // New head is the first non-null head in 0, 1, 2
    return zeroHead ? zeroHead : (oneHead ? oneHead : twoHead);
}
*/

int main()
{
    vector<int> a = {1, 2, 0, 2, 1, 0};
    ListNode *head = vector_to_ll(a);
    cout << "initial ll : ";
    print_LL(head);
    sort(head);
    cout << "sorted ll : ";
    print_LL(head);
}