// Accepted
// 没有找到合适的方法在遍历树的时候就使奇数层reverse
// 我的解决办法是在生成每一层的正序（从左到右）的数列后reverse奇数行


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        LevelTraversal(root, 0);
        if(result.size() > 0) {
        	for(int i = 0; i < result.size(); i++) {
        		if(i%2 ==1)
        			reverse(result[i].begin(), result[i].end());
        	}
        }
        return result;
    }

private:
	vector<vector<int>> result;
	void LevelTraversal(TreeNode* p, int level) {
		if(p != NULL) {
			if(level >= result.size()) {
				vector<int> temp;
				result.push_back(temp);
			}
			result[level].push_back(p->val);
			LevelTraversal(p->left, level+1);
			LevelTraversal(p->right, level+1);
		}
	}
};






