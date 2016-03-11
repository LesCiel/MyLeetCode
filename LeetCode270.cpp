// Accepted


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
    int closestValue(TreeNode* root, double target) {
    	mindiff = 999999999999999;
        ClosestValueCore(root,target);
        return result;
    }

private:
	int result;
	double mindiff;
	void ClosestValueCore(TreeNode* p,double target) {
		if(p != NULL) {
			ClosestValueCore(p->left,target);
			double temp = abs(double(p->val) - target);
			if(temp < mindiff) {
				mindiff = temp;
				result = p->val;
			}
			ClosestValueCore(p->right,target);
		}
	}
};