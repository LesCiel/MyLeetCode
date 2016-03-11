// accepted

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
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL)
    		return NULL;
    	ListNode* p = head->next;
    	ListNode* H = head;
    	while(p) {
    		head->next = p->next;
    		p->next = H;
    		H = p;
    		p = head->next;
    	} 
    	return H; 
    }
};