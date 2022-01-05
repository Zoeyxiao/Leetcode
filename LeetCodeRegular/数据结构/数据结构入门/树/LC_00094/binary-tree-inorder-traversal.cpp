/*
94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：
输入：root = []
输出：[]
示例 3：
输入：root = [1]
输出：[1]
示例 4：
输入：root = [1,2]
输出：[2,1]
示例 5：
输入：root = [1,null,2]
输出：[1,2]
 
提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
 
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
    void inorder(TreeNode *root, vector<int>& res){
        if (root == nullptr){
            return;
        }
        inorder(root -> left, res);
        res.emplace_back(root -> val);
        inorder(root -> right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
}; // 递归方式

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        TreeNode *cur = root, *mostright = nullptr;

        while(cur != nullptr){
            mostright = cur->left;
            if(mostright != nullptr){
                while(mostright -> right != nullptr && mostright -> right != cur){
                    mostright = mostright->right;
                }
                if(mostright -> right == nullptr){
                     mostright -> right = cur;
                     cur = cur -> left;
                } 
                else{
                    res.emplace_back(cur -> val);
                    mostright -> right = nullptr;
                    cur = cur -> right;
                }
            }
            else{
                res.emplace_back(cur -> val);
                cur = cur -> right;
            }    
        }
        return res;
    }
}; //Morris遍历算法
