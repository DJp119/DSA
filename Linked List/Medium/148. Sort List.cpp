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
//  brute force approach , using space of o(n) and time of n logn
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next==nullptr) return head;
        vector<int>temp;
        ListNode* temp2=head;
        while(temp2){
            temp.push_back(temp2->val);
            temp2=temp2->next;
        }
        sort(temp.begin(),temp.end());
        ListNode* finalans = new ListNode(0);
        ListNode* ans=finalans;
        for(int i = 0;i<temp.size();i++){
            ListNode* dummy = new ListNode(temp[i]);
            ans->next=dummy;
            ans = ans->next;
        }
        return finalans->next;
    }
};

class Solution {
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        // due to useing of merge sort , need to modify the algo fast , part
        // to get the prev nod of middle , according to the merge sort rule
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* mergeTwoList(ListNode* left, ListNode* right) {
        ListNode* finalList = new ListNode(0);
        ListNode* temp = finalList;
        while (left && right) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        if (left)
            temp->next = left;
        else
            temp->next = right;

        return finalList->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        // find the middle
        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);

        // merge two list
        return mergeTwoList(left, right);
    }
};


https://leetcode.com/problems/sort-list/
