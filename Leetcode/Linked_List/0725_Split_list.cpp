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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       int N = 0;
       ListNode *curr = head;

       while (curr != NULL){
       	N++;
       	curr = curr->next;
       }

       int mod = N%k;
       int size = N/k;

       vector<ListNode*> ret(k);

       for (int  i = 0; curr != NULL && i < k; i++ ){
       	ret[i] = curr;

       	int currSize = size + (mod-- > 0 ? 1: 0);

       	for (int j = 0; j<currSize -1; j++){
       		curr = curr->next;

       	}
       	ListNode *next = curr->next;
       	curr->next = NULL;
       	curr = next;
       }
       return ret;
    }
};