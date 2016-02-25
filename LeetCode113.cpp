// Accepted
// don't worry how to retrieve the path when reaches leaf.
// record every path in advance to make it easy when path information is needed.



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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

    	if(root == NULL)
    		return v;
    	SUM = sum;
    	int k = 0;
    	sumCore(root, k);
    	return v;
        
    }
private:
	vector<vector<int>> v;
	vector<int> temp;
	int SUM;

	void sumCore(TreeNode* p, int& sum) {
		sum = sum + p->val;
		temp.push_back(p->val);

		if(p->left != NULL)
			sumCore(p->left, sum);
		if(p->right != NULL)
			sumCore(p->right, sum);
		if(p->right == NULL && p->left == NULL) {
			if(sum == SUM) {
				v.push_back(temp);
			}		
		}
		temp.pop_back();
		sum = sum - p->val;
	}
};







