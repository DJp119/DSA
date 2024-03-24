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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummynode = new ListNode(0);
        ListNode* tail = dummynode;
        int carry = 0 ;
        while(l1 != nullptr || l2 != nullptr || carry!= 0 ){
            
            int digit1 = 0;
            int digit2 = 0;
            
            if(l1 != nullptr) {
                digit1 = l1->val;
            }
            if(l2 != nullptr){
                digit2 = l2->val;
            }
            int sum = digit1+digit2+carry;
            int digit = sum % 10 ;
            carry = sum/10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
            

        }
    ListNode * result = dummynode->next;
    delete dummynode;
    return result;
    }
};





// read the question paper properly 
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
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
//         // reverse the list
//         ListNode* rev1 = l1;
//         ListNode* rev2 = l2;

//         ListNode* curr = l1;
//         ListNode* prev = NULL;
//         while(curr){
//             ListNode* forward = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = forward;
//         }
//         rev1 = prev;

//         curr = l2;
//         prev = NULL;
//         while(curr){
//             ListNode* forward = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = forward;
//         }
//         rev2 = prev;

//         //  two list are reversed 


//         ListNode* ans = new ListNode(0);
//         ListNode* temp = ans;
//         int carry = 0 ;
//         while(rev1 && rev2){
//             int tempadd = rev1->val + rev2->val + carry;
//             carry = tempadd % 10;
//             tempadd = tempadd/10;
//             ListNode* dummy = new ListNode(tempadd);
//             temp->next = dummy;
//             temp = dummy;
//             temp = temp->next;
//         }
//         return ans->next;
//     }
// };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        int carry = 0;
        while(l1 || l2){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        if(carry > 0){
            ListNode* node = new ListNode(carry);
            temp->next = node;
        }
        return ans->next;
    }
};


https://leetcode.com/problems/add-two-numbers/
