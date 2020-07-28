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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left_height = maxDepth(root -> left);
        int right_height = maxDepth(root -> right);
        return max(left_height, right_height) + 1;
    }
};

/*
用递归实现的深度优先算法
*/
