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
    vector<int> inorderTraversal(TreeNode* root) {
    	stack<TreeNode*> st;
    	vector<int> inorder;
    	TreeNode* p = root;

    	while(true){
    		if(p != NULL){
    			st.push(p);
    			p = p->left;
    		}
    		else if(st.empty())
    			break;
    		else{
    			p = st.top();
    			inorder.push_back(p->val);
    			st.pop();
    			p = p->right;
    		}
    	} 
    	return inorder;       
    }
};