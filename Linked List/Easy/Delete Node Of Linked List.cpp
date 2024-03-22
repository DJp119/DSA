/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
Node *deleteLast(Node *list){
    Node* temp = list;
    while(temp->next->next != nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return list;
}

https://www.codingninjas.com/studio/problems/delete-node-of-linked-list_8160463?leftPanelTabValue=PROBLEM
