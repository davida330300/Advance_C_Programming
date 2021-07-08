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
    ListNode* reverseList(ListNode* head) {

    	if (head == NULL) return head;
        
    	ListNode *prev = NULL;

        while(head){
        	/**
					a				b		->		c    ->			d
					(prev)		    (head,next)
        	*/        	
        	ListNode *next = head->next;
        	/**
					a			    b		->		c    ->			d
					(prev)		    (head)		   (next)
        	*/
        	head->next = prev;
        	/**
					a		<-		b		  		c    ->			d
					(prev)		(head)		(next)
        	*/
        	prev = head;
        	/**
					a      <-       b		 		c    ->			d
						    	    (prev,head)     (next)
        	*/        	
        	head = next;
        	/**
					a      <-       b				c    ->			d
						    		(prev)		    (head,next)
        	*/        	

        }
        return prev;
    }
};
