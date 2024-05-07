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
    ListNode* doubleIt(ListNode* head) {
        ListNode *curr = head;

        while(curr!=NULL){
            int val = curr->val*2;
            curr->val = val%10;
            if(curr==head and val >=10){
                ListNode *newNode = new ListNode(1);
                head = newNode;
                head->next = curr;
            }
            if(curr->next!=NULL and curr->next->val*2 >=10){
                curr->val+=1;
            }
            curr = curr->next;
        }
        return head;
    }
};
