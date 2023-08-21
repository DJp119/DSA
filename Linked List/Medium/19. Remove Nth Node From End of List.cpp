/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        if(head == NULL) return 0;

        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        int len = length(head);
        if(n == len) return head->next;
        if(n > len) return head;


        ListNode*temp = head;
        int count = 1;
        while(temp!= NULL && count < len - n){
            temp = temp->next;
            count++;
        }
        temp->next = temp->next->next;

        return head;
    }
};


*****************App - 2 ****************************
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();

        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;

        for(int i = 1 ; i <=n ;i++){
            fast = fast->next;
        }
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return start->next;
    }
};
