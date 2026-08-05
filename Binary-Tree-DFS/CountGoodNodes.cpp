
using namespace std;
#include <algorithm> // for std::max
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Count Good Nodes in Binary Tree
// Approach: DFS passing down maxSoFar (largest value seen on path from root).
// A node is good if its value >= maxSoFar.
// Time: O(n) — visits every node once
// Space: O(h) — recursion stack, h = height of tree
class Solution {
public:
    int count=0;
    void dfs(TreeNode* root, int MaxSoFar){
        if(root==nullptr){return ;}
        if(root->val>=MaxSoFar){
            MaxSoFar=root->val;
            count++;
        }

        dfs(root->left,MaxSoFar);
        dfs(root->right,MaxSoFar);
    }
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return count;
        
    }
};