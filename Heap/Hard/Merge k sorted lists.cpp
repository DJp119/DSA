#include <queue>
class compare{
    public:
    bool operator()(Node*a,Node*b) {
        return a->data > b->data;
    }
};
Node* mergeKLists(vector<Node*> &listArray)
{
    priority_queue<Node*,vector<Node*>,compare>minHeap;
    int k = listArray.size();
    if(k==0) return NULL;
    for(int i=0;i<k;i++){
        if(listArray[i]!=NULL){
            minHeap.push(listArray[i]);
        }
    }
    Node* head = NULL;
    Node* tail = NULL;
    while(minHeap.size()>0){
        Node* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL){
            minHeap.push(top->next);
        }
        if(head == NULL){ // answer LL is empty
            head = top;
            tail = top;
        }
        else{// insert at linked list
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
TC-O(k log k)+O(n*k log k)     n-> no of nodes in LL
SC - O(k)
