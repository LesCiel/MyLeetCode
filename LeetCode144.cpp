// accepted


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
    vector<int> preorderTraversal(TreeNode* root) {
    	stack<TreeNode*> st;
    	vector<int> preorder;
    	TreeNode *p = root;
    	while(true) {
    		if(p != NULL) {
    			preorder.push_back(p->val);
    			st.push(p);
    			p = p->left;
    		}
    		else {
    			if(st.empty())
    				break;
    			p = st.top()->right;
    			st.pop();
    		}
    	}
    	return preorder;
    }
};