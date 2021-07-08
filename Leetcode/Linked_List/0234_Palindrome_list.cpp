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
	bool isPalindrome(ListNode* head) {
		stack<int> s;
		ListNode *curr = head;

		while(curr){
			s.push(curr->val);
			curr = curr->val;
		}
		while(head){
			int v = s.top();
			s.pop();
			if (v != head->val) return false;
			head = head->next;
		}
		return true;
	}	
};

class Solution{
public:
	int getSize(ListNode* head) {
        int c = 0;
        while(head) {
            c++;
            head = head->next;
        }
        return c;
    }
    
    ListNode* reverseSecondHalf(ListNode* t) {
        if (!t->next) return t;
        ListNode* t1 = t;
        ListNode* t2 = t1->next;
        ListNode* t3 = t2->next;
        while (t3) {
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            t3 = t2->next;
        }
        t2->next = t1;
        t->next = NULL;
        t = t2;
        return t;
    }
    bool isPalindrome(ListNode* head) {
        if (!head->next) return true;
        int mid = ceil(getSize(head)/2.0);
        int c = 0;
        ListNode* root = head;
        ListNode* sh = NULL;
        while(root) {
            c++;
            if (c > mid) {
                sh = reverseSecondHalf(root);
                break;
            }
            root = root->next;
        }
        root = head;
        c = 0;
        while(root && sh && c++ < mid) {
            if (root->val != sh->val) return false;
            root = root->next;
            sh = sh->next;
        }
        return true;
    }	
};