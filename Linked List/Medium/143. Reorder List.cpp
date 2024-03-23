// Error in the freeing meemory   
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if(!head) return;
//         ListNode* right1=nullptr;
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast->next && fast->next->next){
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         if(fast->next) slow=slow->next;
        
//         right1 = slow;  // rigth part 
//         // reverse the right part after the mid
//         ListNode* curr = right1;
//         ListNode* prev = nullptr;
//         while(right1){
//             ListNode* forward = right1->next;
//             right1->next = prev;
//             prev = right1;
//             right1=forward;
//         }

//         // here prev is the head of reverse list of right part
//         ListNode* dummy1 = NULL;
//         ListNode* dummy2 = NULL;
//         while(head && prev){
//             dummy1=head->next;
//             dummy2=prev->next;
            
//             head->next=prev;
//             if(dummy1)  prev->next=dummy1;
            
//             head=dummy1;
//             prev=dummy2;

//         }
//         if(head ) head->next=NULL;
//     }
// };
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return; // Check if the list is empty or has only one element

        // Finding the midpoint of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Splitting the list into two halves
        ListNode* rightHalf = slow->next;
        slow->next = nullptr;

        // Reversing the second half of the list
        ListNode* prev = nullptr;
        ListNode* current = rightHalf;
        while (current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        rightHalf = prev; // Now rightHalf points to the head of the reversed list

        // Merging the two halves alternately
        ListNode* left = head;
        while (left && rightHalf) {
            ListNode* nextLeft = left->next;
            ListNode* nextRight = rightHalf->next;

            left->next = rightHalf;
            rightHalf->next = nextLeft;

            left = nextLeft;
            rightHalf = nextRight;
        }
    }
};


https://leetcode.com/problems/reorder-list/?envType=daily-question&envId=2024-03-23
