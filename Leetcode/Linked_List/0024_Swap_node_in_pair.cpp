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
    ListNode* swapPairs(ListNode* head) {

    	if (head == NULL) return NULL;
    	if (head->next == NULL) return head;

    	ListNode *ret = head->next;

    	ListNode *prev = new ListNode();
    	prev->next = head;

    	while(prev->next && prev->next->next){


    		ListNode *first = prev->next;
    		ListNode *second = prev->next->next;

    		// prev -> 1 -> 2 -> 3 -> 4
    		ListNode *next = second->next;
    		// prev -> 1 -> 2 -> 3 -> 4
    		//									(next)
    		first->next = next;
    		second->next = first;
    		prev->next = second;
    		// correct connection with previous node

    		prev = first;

    	}
    	return ret;
    }
};
