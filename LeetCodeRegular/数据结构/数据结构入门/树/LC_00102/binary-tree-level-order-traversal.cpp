/*
102. 二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层序遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        } //如果根节点为空，直接返回空

        queue <TreeNode*> q; //定义一个以根节点为输入类型的队列
        q.push(root);
         
        while(!q.empty()){
            int currentLevelSize = q.size();
            res.push_back(vector<int> ());  //给res末尾添加一个新的一维向量
            for (int i = 1; i <= currentLevelSize; ++i){
                auto node = q.front(); 
                q.pop();
                res.back().push_back(node->val);
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
        }
        return res;
    }
};

/*
若res = [[1,2],[3,4],[5,6,7]]，res.back()就是res这个（外层）vector里的最后一个元素，那么这里就是[5,6,7]（也是一个vector），这个元素调用vector的push_back()方法（其实就是python list的append方法），就是在其尾部插入一个新元素，假如你那里node->val 是8，最终结果就变为：res = [[1,2],[3,4],[5,6,7,8]]
*/
