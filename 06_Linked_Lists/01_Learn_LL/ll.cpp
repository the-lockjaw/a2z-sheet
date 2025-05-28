#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void print_LL(Node *head)
{
    Node *temp = head; // just in case we need head again, out of habit
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next; // IMPORTANT
    }
    cout << endl;
}

Node *vector_to_ll(vector<int> v)
{
    if (v.empty())
        return nullptr;

    // initialise w/ first value
    Node *head = new Node(v[0]);
    Node *temp = head;

    // iterate till end of vector
    for (int i = 1; i < v.size(); i++)
    {
        Node *new_node = new Node(v[i]);
        temp->next = new_node;
        temp = temp->next;
    }
    return head;
}

Node *insert_at_head(Node *head, int val)
{
    Node *new_node = new Node(val, head);
    return new_node;
}

// delete a node from its pointer
// LC 237
void deleteNode(Node *node)
{
    // Overwrite data of next node on current node.
    node->data = node->next->data;
    // Make current node point to next of next node.
    node->next = node->next->next;
}

int length_of_ll(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

bool search_in_ll(Node *head, int target)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == target)
            return true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = vector_to_ll(v);
    print_LL(head);
    head = insert_at_head(head, 15);
    print_LL(head);
    cout << "Length of LL = " << length_of_ll(head) << endl;
    int target = 6;
    if (search_in_ll(head, target))
    {
        cout << target << " was found." << endl;
    }
    else
    {
        cout << target << " was NOT found." << endl;
    }
}