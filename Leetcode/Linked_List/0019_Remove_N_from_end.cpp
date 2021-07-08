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
      int size = 0;
      ListNode *curr = head;
      while(curr){
        curr = curr->next;
        size ++;
      }

      int pos = size-n;
      curr = head;
        
      if (pos == 0){
        head = curr->next;
        return head;
      }

      for (int i = 0; i<pos; i++){
        curr= curr-> next;
      }
      
      ListNode *prev = curr;
      ListNode *deleteNode = curr->next;
      ListNode *next = curr->next->next;

      prev->next = next;
      deleteNode->next = NULL;
      delete(deleteNode);
      return head;
    }
    
};