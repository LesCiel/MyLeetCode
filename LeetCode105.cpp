// Accepted
// notice: in the recursive function BuildCore(), parameters preorder and inorder should be added &.
// Otherwise memory limit will be exceeded.



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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return BuildCore(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

private:
	TreeNode* BuildCore(vector<int>& preorder, int beginP, int endP, vector<int>& inorder, int beginI, int endI) {
		if(beginP > endP)
			return NULL;

		int i;
		for(i = beginI; i <= endI; i++) {
			if(inorder[i] == preorder[beginP])
				break;
		}
		TreeNode* root = new TreeNode(preorder[beginP]);
		root->left = BuildCore(preorder, beginP+1, beginP+(i-beginI), inorder, beginI, i-1);
		root->right = BuildCore(preorder, beginP+(i-beginI)+1, endP, inorder, i+1, endI);
		return root;
	}
};

