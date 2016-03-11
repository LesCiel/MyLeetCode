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
    bool isValidBST(TreeNode* root) {
    	ValidFlag = true;
    	FirstNode = true;
        isValidBSTCore(root);
        return ValidFlag;
    }

private:
	bool ValidFlag;
	int preval;
	bool FirstNode;
	void isValidBSTCore(TreeNode* p) {
		if(p) {
			isValidBSTCore(p->left);
			if(FirstNode) {
				preval = p->val;
				FirstNode = false;
			}
			else {
				if(p->val <= preval) {
					ValidFlag = false;
					return;
				}
				preval = p->val;
			}
			isValidBSTCore(p->right);
		}
	}
};





