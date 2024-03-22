//fast and slow pointer approach

bool hasCycle(ListNode *head) {
   ListNode* slow=head;
   ListNode* fast=head;
    while(fast && slow && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
            return true;
    }
    return false;
}

//hashmap approach

bool hasCycle(ListNode *head) {
    if(head==NULL)
        return false;
    unordered_map<ListNode*,int> map;
    while(head!=NULL){
        if(map.count(head)>0)
            return true;
        else
            map[head]=1;
        head=head->next;
    }
    return false;
}

        if(head==NULL) return head;
        ListNode* temp = head;
        unordered_map<ListNode*,int>mymap;
        while(temp->next){
            if(mymap.find(temp)!=mymap.end()) return true;
            mymap[temp]=1;
            temp = temp->next;
        }
        return false;


https://leetcode.com/problems/linked-list-cycle/description/
