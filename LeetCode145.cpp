//accepted
// left -> right ->root
// modify the preorder algorithm to "root -> right -> left"(just switch left and right)
// and use another stack to reverse it.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	stack<TreeNode*> st; 
    	stack<int> st2;
    	vector<int> postorder;
    	TreeNode* p = root;

    	while(true) {
    		if(p != NULL) {
    			st2.push(p->val);
    			st.push(p);
    			p = p->right;
    		}
    		else {
    			if(st.empty())
    				break;
    			p = st.top()->left;
    			st.pop();
    		}
    	}
    	while(!st2.empty()) {
    		postorder.push_back(st2.top());
    		st2.pop();
    	} 
    	return postorder;
    }
};