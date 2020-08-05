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
    unordered_map <TreeNode*, int> f, g; //unordered_map <key value>  哈希函数的定义方法，感觉用普通的堆或者栈也可以

    void dfs(TreeNode* o) {
        if (!o) {
            return;
        }
        dfs(o->left);
        dfs(o->right);
        f[o] = o->val + g[o->left] + g[o->right];
        g[o] = max(f[o->left], g[o->left]) + max(f[o->right], g[o->right]);
    }

    int rob(TreeNode* o) {
        dfs(o);
        return max(f[o], g[o]);
    }
};

/*
进阶版的打家劫舍问题，不过动态规划的思路不变，讨论情况分为当前节点的状态为选择或不选择进行讨论即可；用深度优先就可以实现
*/
