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
    int sumNumbers(TreeNode* root) {
    	if(root == NULL)
    		return 0;
    	int k = 0;
    	sumCore(root, k);
    	int sum = 0;
        for(int i = 0; i < v.size(); i++)
        	sum = sum + v[i];
        return sum;
    }

private:
	vector<int> v;
	void sumCore(TreeNode* p, int& sum) {
		sum = sum*10 + p->val;
		if(p->left != NULL)
			sumCore(p->left, sum);
		if(p->right != NULL)
			sumCore(p->right, sum);
		if(p->right == NULL && p->left == NULL)
			v.push_back(sum);
		sum = (sum - p->val)/10;
	}
};


