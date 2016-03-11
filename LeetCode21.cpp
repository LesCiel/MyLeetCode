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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
    	ListNode* p = l1;
    	ListNode* q = NULL;
    	ListNode* tmp;
    	while(p!=NULL && l2!=NULL) {
    		if(p->val <= l2->val) {
    			q = p;
    			p = p->next;
    		}
    		else {
    			if(q!=NULL) {
    				q->next = l2;
    				l2 = l2->next;
    				q->next->next = p;
    				q = q->next;
    			}
    			else {
    				l1 = l2;
    				l2 = l2->next;
    				l1->next = p;
    				q = l1;
    			}
    		}
    	}
    	if(p == NULL)
    	    q->next = l2;
    	return l1;  
    }
};




// Recursive method

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}