struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Search in a Binary Search Tree
// Approach: use BST ordering property — at each node, go left if val is smaller,
// right if val is larger, since BST guarantees the target can only be on that side.
// Time: O(h) — h = height of tree (O(log n) balanced, O(n) worst case skewed)
// Space: O(h) — recursion stack
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr; // value not found

        if (root->val == val) return root; // found the match, return this subtree

        if (val < root->val) return searchBST(root->left, val);

        return searchBST(root->right, val);
    }
};