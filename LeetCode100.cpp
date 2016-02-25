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
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	TestCore(p,q);
        return same;
    }

private:
	bool same = true;
	void TestCore(TreeNode* p, TreeNode* q) {
		if(same == false)
			return;
		if(p == NULL && q == NULL)
			return;
		else if(p != NULL && q != NULL) {
			if(p->val != q->val) {
				same = false;
				return;
			}
			else {
				TestCore(p->left, q->left);
				TestCore(p->right, q->right);
			}
		}
		else{
			same = false;
			return;
		}
	}
};






