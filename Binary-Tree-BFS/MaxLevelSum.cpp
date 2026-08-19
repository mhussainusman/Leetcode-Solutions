#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Maximum Level Sum of a Binary Tree
// Approach: Level-order BFS — sum node values per level,
// track the max sum and the (smallest) level number that achieved it.
// Time: O(n) — every node visited exactly once
// Space: O(n) — worst case, queue holds the widest level of the tree
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int maxLevel = 0;
        int maxSum = INT_MIN;

        while (!q.empty()) {
            level++;
            int levelSum = 0;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left != nullptr) { q.push(node->left); }
                if (node->right != nullptr) { q.push(node->right); }
            }

            if (levelSum > maxSum) {
                maxLevel = level;
                maxSum = levelSum;
            }
        }

        return maxLevel;
    }
};