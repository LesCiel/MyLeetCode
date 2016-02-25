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
    int minDepth(TreeNode* root) {
    	if(root == NULL)
    		return 0;
    	mindepth = 100000000;
    	int depth = 0;
    	PathCore(root, depth);
    	return mindepth;       
    }
    
private:
	int mindepth;
	void PathCore(TreeNode* p, int& depth) {
		depth++;
		if(p->left != NULL)
			PathCore(p->left, depth);
		if(p->right != NULL)
			PathCore(p->right, depth);
		if(p->right == NULL && p->left == NULL) {
			if(depth < mindepth)
				mindepth = depth;
		}
		depth--;
	}  
};