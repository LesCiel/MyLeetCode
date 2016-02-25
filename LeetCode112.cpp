// accepted
// very similar with LeetCode 129

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
    bool hasPathSum(TreeNode* root, int s) {
    	if(root == NULL)
    		return exist;
    	SUM = s;
    	int k = 0;
    	sumCore(root, k);
    	return exist;
    }

private:
	vector<int> v;
	int SUM;
	bool exist = false;
	void sumCore(TreeNode* p, int& sum) {
		sum = sum + p->val;
		if(p->left != NULL)
			sumCore(p->left, sum);
		if(p->right != NULL)
			sumCore(p->right, sum);
		if(p->right == NULL && p->left == NULL) {
			if(sum == SUM)
				exist = true;
		}
		sum = sum - p->val;
	}
};