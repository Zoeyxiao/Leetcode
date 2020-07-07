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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr){
            return false;
        }
        queue<TreeNode *> que_node;
        queue<int> que_val;
        que_node.push(root);
        que_val.push(root -> val);

        while(!que_node.empty()){
            TreeNode *now = que_node.front();
            int mid = que_val.front();
            que_node.pop();
            que_val.pop();
            if(now -> left == nullptr && now -> right == nullptr){
                if (mid == sum) return true;
                continue;
            }
            if(now -> left != nullptr){
                que_node.push(now -> left);
                que_val.push(now -> left -> val + mid);
            }
            if(now -> right != nullptr){
                que_node.push(now -> right);
                que_val.push(now -> right -> val + mid);
            }
        }
        return false;
    }
};

/*
今天这个题主要在于使用两个队列，分别存储要遍历的节点，以及根节点到这些节点的路径；使用广度优先搜索即可
我遇到的问题是对与队列和二叉树的访问命令不熟悉，需要进一步熟悉
*/
