/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         
      ListNode *Aptr = headA;
      ListNode *Bptr = headB;

      if(!Aptr || !Bptr) return NULL;

      while(Aptr != Bptr){	// error: Aptr->val 
      	if (Aptr == NULL) { Aptr = headB;}	// error: Aptr->next == NULL
      	else {Aptr = Aptr->next;}

      	if (Bptr == NULL) { Bptr = headA;}
      	else {Bptr = Bptr->next;}
      }
      return Aptr;
    }
};