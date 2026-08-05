#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Maximum Depth of Binary Tree
// Approach: DFS recursion — depth of a tree = 1 + max(left subtree depth, right subtree depth)
// Time: O(n) — visits every node once
// Space: O(h) — recursion stack, h = height of tree (O(n) worst case, O(log n) best case)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0; // base case: empty tree has depth 0

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};