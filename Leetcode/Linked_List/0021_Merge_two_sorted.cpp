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
// iterative
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
      if (l1 == NULL) return l2;
      if (l2 == NULL) return l1;

      ListNode *head = new ListNode();
      ListNode *ret = head;
      ListNode *curr;

      while(l1 && l2){
      	if (l1->val >= l2->val){
      		curr = new ListNode(l2->val);
      		ret->next = curr;
      		ret = ret->next;
      		l2 = l2->next;
      	}else{
      		curr = new ListNode(l1->val);
      		ret->next = curr;
      		ret = ret->next;
      		l1 = l1->next;
      	}
      }
      if (l1) ret->next = l1;
      if (l2) ret->next = l2;

      return head->next;
    }
};
// recursive
class Solution{
public:
	ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
	}
}