
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Binary Tree Right Side View
// Approach: Level-order BFS — process level by level using queue,
// record the last node processed in each level (rightmost visible node).
// Time: O(n) — every node visited exactly once
// Space: O(n) — worst case, last level of a complete tree holds up to ~n/2 nodes in the queue

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // freeze count of nodes in current level

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (i == levelSize - 1) {
                    result.push_back(node->val); // last node in this level = rightmost
                }

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return result;
    }
};