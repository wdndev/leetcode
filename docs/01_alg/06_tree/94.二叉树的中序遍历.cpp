/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (76.30%)
 * Likes:    1947
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
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
    // 1.递归
    vector<int> inorderTraversal1(TreeNode* root) {
        std::vector<int> ans;
        this->inorder(root, ans);

        return ans;
    }

    // 2.手动维护栈
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;

        if (root == nullptr) {
            return ans;
        }
        
        std::stack<TreeNode*> stack;

        while (root != nullptr || !stack.empty()) {
            // 左子树加入栈
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }

            // 栈中取出
            root = stack.top();
            stack.pop();
            ans.push_back(root->val);

            // 遍历右子树
            root = root->right;
        }

        return ans;
    }

private:
    void inorder(TreeNode* root, std::vector<int>& ans) {
        if (!root) {
            return;
        }
        this->inorder(root->left, ans);
        ans.push_back(root->val);
        this->inorder(root->right, ans);
    }
};
// @lc code=end

