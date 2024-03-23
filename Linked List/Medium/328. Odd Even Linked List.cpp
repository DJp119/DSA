class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head; // No need to process if there are 0, 1, or 2 nodes
        
        queue<ListNode*> oddNodes;
        queue<ListNode*> evenNodes;
        
        ListNode* curr = head;
        int index = 1;
        
        // Split nodes into odd and even queues
        while (curr) {
            if (index % 2 == 0) {
                evenNodes.push(curr);
            } else {
                oddNodes.push(curr);
            }
            curr = curr->next;
            index++;
        }
        
        // Create a new list using nodes from both queues alternately
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        
        while (!oddNodes.empty() || !evenNodes.empty()) {
            if (!oddNodes.empty()) {
                tail->next = oddNodes.front();
                oddNodes.front()->next = nullptr;
                oddNodes.pop();
                tail = tail->next;
            }
            
            if (!evenNodes.empty()) {
                tail->next = evenNodes.front();
                evenNodes.front()->next = nullptr;
                evenNodes.pop();
                tail = tail->next;
            }
        }
        return dummy->next;
    }
};

class Solution{
    public:
    ListNode* oddEvenList(ListNode* head){
        if(!head || !head->next || !head->next->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode*even_start =head->next;

        while(odd->next && even->next){
            odd->next = even->next;
            even->next = odd->next->next;
            odd=odd->next;
            even = even->next;
        }
        odd->next=even_start;
        return head;
    
    }
};




https://leetcode.com/problems/odd-even-linked-list/
