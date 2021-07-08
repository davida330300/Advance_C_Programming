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
        
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        
        int sum = l1->val+l2->val;
        int carry = sum/10;

        ListNode *ret = new ListNode(sum%10);
        ListNode *cur = ret;
       
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1!=NULL && l2!=NULL){
            sum = l1->val+l2->val+carry;
            carry = sum/10;
            ListNode *newNode = new ListNode(sum%10);
            cur->next = newNode;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            sum = l1->val+carry;
            carry = sum/10;
            ListNode *newNode = new ListNode(sum%10);
            cur->next = newNode;
            cur = cur->next;
            l1 = l1->next;    
        }    
        while(l2!=NULL){
            sum = l2->val+carry;
            carry = sum/10;
            ListNode *newNode = new ListNode(sum%10);
            cur->next = newNode;
            cur = cur->next;
            l2 = l2->next;  
        }
        if (carry!=0){
            ListNode *newNode = new ListNode(carry);
            cur->next = newNode;
        }
        return ret;
        
    }
};