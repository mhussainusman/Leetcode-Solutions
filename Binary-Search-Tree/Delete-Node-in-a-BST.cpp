struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Delete Node in a BST
// Approach: search using BST property, then handle deletion by case:
// 0 children -> remove directly. 1 child -> promote that child.
// 2 children -> replace value with in-order successor (min of right subtree),
// then recursively delete that successor from the right subtree.
// Time: O(h) — h = height of tree (O(log n) balanced, O(n) worst case)
// Space: O(h) — recursion stack
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr; // key not found

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // found the node to delete

            if (root->left == nullptr && root->right == nullptr) {
                return nullptr; // Case 1: leaf
            }
            if (root->left == nullptr) {
                return root->right; // Case 2: only right child
            }
            if (root->right == nullptr) {
                return root->left; // Case 2: only left child
            }

            // Case 3: two children — find in-order successor (min of right subtree)
            TreeNode* successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }

            root->val = successor->val; // copy successor's value into this node
            root->right = deleteNode(root->right, successor->val); // remove the duplicate
        }

        return root;
    }
};