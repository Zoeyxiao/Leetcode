/*
145. 二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
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
    void postorder(TreeNode *root, vector<int> &res){
        if(root == nullptr){
            return;
        }
        postorder(root->left, res);
        postorder(root->right, res);
        res.emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
}; //递归方式

class Solution {
public:
    //储存右子树的访问路径，并倒序输出
    void addPath(vector<int> &vec, TreeNode *node) {
        int count = 0;
        while (node != nullptr) {
            ++count;
            vec.emplace_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        TreeNode *cur = root, *mostright = nullptr;
        while(cur != nullptr){
            mostright = cur -> left;
            if(mostright != nullptr){
                while(mostright -> right != nullptr && mostright -> right != cur){
                mostright = mostright->right;
                }
                if(mostright->right == nullptr){
                    mostright->right = cur;
                    cur = cur->left;
                    continue;
                }
                else{
                    mostright->right = nullptr;
                    addPath(res, cur->left);
                }                
            }
            cur = cur->right;            
        }
        addPath(res, root);
        return res;
    }
};
