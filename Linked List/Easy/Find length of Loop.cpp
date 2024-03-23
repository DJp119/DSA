/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
int lengthOfLoop(Node *head) {
    int len=1;
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next){
        slow=slow->next;
        fast = fast->next->next;

        if(fast == slow){
            fast=fast->next;
            while(fast != slow){
                len++;
                fast=fast->next;
            }
            return len;
        }
    }
    return 0;
}


https://www.codingninjas.com/studio/problems/find-length-of-loop_8160455?leftPanelTabValue=PROBLEM
