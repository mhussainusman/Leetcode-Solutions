#include <algorithm> // for std::max
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Leaf-Similar Trees
// Approach: DFS to collect leaf values (left to right) for both trees, then compare.
// Time: O(n + m) — visits every node in both trees once
// Space: O(n + m) — for the leaf vectors, plus O(h) recursion stack
class Solution {
public:
    void dfs(TreeNode* node, vector<int>& leaves) {
        if (node == nullptr) return;

        if (node->left == nullptr && node->right == nullptr) {
            leaves.push_back(node->val);
            return;
        }

        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);
        return leaves1 == leaves2;
    }
};