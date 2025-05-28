#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
    Node(int val, Node *next, Node *prev)
    {
        data = val;
        next = next;
        prev = prev;
    }
};

Node *insert_at_end(Node *head, int val)
{
    Node *new_node = new Node(val);

    if (head == nullptr)
        return new_node;

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;

    return head;
}

Node *delete_last_node(Node *head)
{
    Node *temp = head, *prev = nullptr;
    while (temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = nullptr;
    return head;
}

Node *reverse_dll(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head, *prev = nullptr;
    while (temp != nullptr)
    {
        Node *next = temp->next; // for swapping
        temp->prev = next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

Node *vector_to_dll(vector<int> v)
{
    if (v.empty())
        return nullptr;

    Node *head = new Node(v[0]);
    Node *temp = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *new_node = new Node(v[i]);
        temp->next = new_node;
        // MISTAKE:
        new_node->prev = temp;
        temp = new_node;
    }

    return head;
}

void print_dll(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void check_dll(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->prev == nullptr)
        {
            cout << "temp->prev points to nullptr" << endl;
        }
        else
        {
            cout << "temp->prev points to " << temp->prev->data << endl;
        }
        cout << "temp->data = " << temp->data << endl;
        if (temp->next == nullptr)
        {
            cout << "temp->next points to nullptr" << endl;
        }
        else
        {
            cout << "temp->next points to " << temp->next->data << endl;
        }
        cout << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = vector_to_dll(v);
    print_dll(head);

    int a = 67;
    head = insert_at_end(head, a);
    print_dll(head);

    head = delete_last_node(head);
    print_dll(head);
    // check_dll(head);

    head = reverse_dll(head);
    print_dll(head);
}