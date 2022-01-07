/*
226. 翻转二叉树
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //递归的终止条件，节点为空时返回；
        if(!root){
            return nullptr;
        }
        //将当前节点的左右子树交换
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp; 
        //递归交换当前节点的左子树
        invertTree(root->left);
        //递归交换当前节点的右子树
        invertTree(root->right);
        //都交换完了，返回整棵树
        return root;
    }
};
